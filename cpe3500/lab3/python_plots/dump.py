import gdb

N = 20

# Resolve addresses from symbols
step = int(gdb.parse_and_eval("&step"))
expon = int(gdb.parse_and_eval("&expon"))
sinus = int(gdb.parse_and_eval("&sinus"))


def read_int(addr):
    return int(gdb.parse_and_eval(f"*(int*)0x{addr:X}"))


def read_float(addr):
    val = gdb.parse_and_eval(f"*(float*)0x{addr:X}")
    return float(val)


with open("signals.csv", "w") as f:
    f.write("n,delta,step,rect,expon,sinus\n")
    for i in range(N):
        s = read_int(step + i * 4)
        e = read_float(expon + i * 4)
        si = read_float(sinus + i * 4)

        f.write(f"{i},{s},{e},{si}\n")

print("\nSignals exported to signals.csv\n")
