import gdb

N = 20

# Resolve addresses from symbols
rect = int(gdb.parse_and_eval("&rect"))
output = int(gdb.parse_and_eval("&output"))


def read_int(addr):
    return int(gdb.parse_and_eval(f"*(int*)0x{addr:X}"))


def read_float(addr):
    val = gdb.parse_and_eval(f"*(float*)0x{addr:X}")
    return float(val)


with open("signals.csv", "w") as f:
    f.write("n,rect,system1\n")
    for i in range(N):
        e = read_float(rect + i * 4)
        si = read_float(output + i * 4)

        f.write(f"{i},{e},{si}\n")

print("\nSignals exported to signals.csv\n")
