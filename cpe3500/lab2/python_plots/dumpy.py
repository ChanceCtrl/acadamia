import gdb

N = 20

# Resolve addresses from symbols
sinus = int(gdb.parse_and_eval("&sinus"))
comp_sinus = int(gdb.parse_and_eval("&comp_sinus"))


def read_int(addr):
    return int(gdb.parse_and_eval(f"*(int*)0x{addr:X}"))


def read_float(addr):
    val = gdb.parse_and_eval(f"*(float*)0x{addr:X}")
    return float(val)


with open("signals.csv", "w") as f:
    f.write("n,sinus,comp_sinus\n")
    for i in range(N):
        si = read_float(sinus + i * 4)
        csi = read_float(comp_sinus + i * 4)

        f.write(f"{si},{csi}\n")

print("\nSignals exported to signals.csv\n")
