import gdb

N = 1024

file_name = "signals_1.csv"
list_to_export = [
    "input_fft_mag",
    "output_freq",
]
export_addresses = []

# Resolve addresses
for thing in list_to_export:
    export_addresses.append(int(gdb.parse_and_eval(f"&{thing}")))


def read_f32(addr):
    return float(gdb.parse_and_eval(f"*(float *)0x{addr:X}"))


def export_signals():
    with open(file_name, "w") as f:
        f.write("n,")

        for thing in list_to_export:
            f.write(f"{thing},")

        f.write("\n")

        for i in range(N):
            f.write(f"{i},")

            for addr in export_addresses:
                f.write(f"{read_f32(addr + i * 4)},")

            f.write("\n")

    print("\nSignals exported to signals_1.csv\n")


# Breakpoint class
class MatchFreqFinishBreakpoint(gdb.FinishBreakpoint):
    def __init__(self, frame):
        super().__init__(frame, internal=False)

    def stop(self):
        print("match_freq() finished, exporting signals...")
        export_signals()
        return False  # continue execution


class MatchFreqBreakpoint(gdb.Breakpoint):
    def __init__(self):
        super().__init__("match_freq", internal=False)

    def stop(self):
        # When match_freq is entered, set a FinishBreakpoint
        MatchFreqFinishBreakpoint(gdb.newest_frame())
        return False  # continue execution


# Set the breakpoint
MatchFreqBreakpoint()
