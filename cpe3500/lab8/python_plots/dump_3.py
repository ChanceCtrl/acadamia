import gdb

N = 2048

file_name = "signals_3.csv"
list_to_export = ["input_signal", "filtered_signal"]
export_addresses = []

# Resolve addresses
for thing in list_to_export:
    export_addresses.append(int(gdb.parse_and_eval(f"&{thing}")))


def read_u16(addr):
    return int(gdb.parse_and_eval(f"*(unsigned short *)0x{addr:X}"))


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

    print("\nSignals exported to signals.csv\n")


export_signals()
