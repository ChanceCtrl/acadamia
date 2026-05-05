import gdb

N = 2048

# Resolve addresses
in1 = int(gdb.parse_and_eval("&input_signal"))
# dac_buffer = int(gdb.parse_and_eval("&dac_buffer"))


def read_u16(addr):
    return int(gdb.parse_and_eval(f"*(unsigned short *)0x{addr:X}"))


def read_f32(addr):
    return float(gdb.parse_and_eval(f"*(float *)0x{addr:X}"))


def export_signals():
    with open("signals.csv", "w") as f:
        f.write("n,adc_buffer\n")  # match actual columns

        for i in range(N):
            a = read_f32(in1 + i * 4)
            # d = read_u16(dac_buffer + i * 2)

            f.write(f"{i},{a}\n")

    print("\nSignals exported to signals.csv\n")


export_signals()
