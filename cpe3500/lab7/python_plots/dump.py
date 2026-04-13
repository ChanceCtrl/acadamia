import gdb

N = 20_000

# Resolve addresses
adc_buffer = int(gdb.parse_and_eval("&adc_buffer_40k"))
dac_buffer = int(gdb.parse_and_eval("&dac_buffer_40k"))
dac_buffer_2 = int(gdb.parse_and_eval("&dac_buffer_40k_unprocessed"))


def read_u16(addr):
    return int(gdb.parse_and_eval(f"*(unsigned short*)0x{addr:X}"))


def export_signals():
    with open("signals.csv", "w") as f:
        f.write("n,adc_buffer_40k,dac_buffer_40k,dac_buffer_40k_unprocessed\n")
        for i in range(N):
            a = read_u16(adc_buffer + i * 2)
            d = read_u16(dac_buffer + i * 2)
            g = read_u16(dac_buffer_2 + i * 2)
            f.write(f"{i},{a},{d},{g}\n")

    print("\nSignals exported to signals.csv\n")


# Finish breakpoint (runs AFTER function returns)
class ExportAfterReturn(gdb.FinishBreakpoint):
    def __init__(self):
        super().__init__(gdb.newest_frame(), internal=True)

    def stop(self):
        print("\nHAL_ADC_Stop_DMA returned — exporting signals...\n")
        export_signals()
        return False


# Entry breakpoint
class ExportOnDACStop(gdb.Breakpoint):
    def __init__(self):
        super().__init__("HAL_ADC_Stop_DMA", gdb.BP_BREAKPOINT)
        self.silent = True
        self.done = False

    def stop(self):
        # Prevent multiple triggers
        if not self.done:
            self.done = True
            ExportAfterReturn()
        return False


ExportOnDACStop()

print("Waiting for HAL_ADC_Stop_DMA to complete before exporting...\n")
