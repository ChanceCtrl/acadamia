import gdb

N = 41

# Resolve addresses from symbols
sine1 = int(gdb.parse_and_eval("&sine1"))
sine2 = int(gdb.parse_and_eval("&sineComposite"))
sine3 = int(gdb.parse_and_eval("&sineFiltered"))


def read_int(addr):
    return int(gdb.parse_and_eval(f"*(int*)0x{addr:X}"))


def read_float(addr):
    val = gdb.parse_and_eval(f"*(float*)0x{addr:X}")
    return float(val)


with open("signals.csv", "w") as f:
    f.write("n,sine1,sine2,sine3\n")
    for i in range(N):
        s1 = read_float(sine1 + i * 4)
        s2 = read_float(sine2 + i * 4)
        s3 = read_float(sine3 + i * 4)

        f.write(f"{i},{s1},{s2},{s3}\n")

print("\nSignals exported to signals.csv\n")
