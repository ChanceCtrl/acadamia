import gdb
import struct

N = 20

# Resolve addresses from symbols
delta = int(gdb.parse_and_eval("&delta"))
step = int(gdb.parse_and_eval("&step"))
rect = int(gdb.parse_and_eval("&rect"))
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
        d = read_int(delta + i * 4)
        s = read_int(step + i * 4)
        r = read_int(rect + i * 4)
        e = read_float(expon + i * 4)
        si = read_float(sinus + i * 4)

        f.write(f"{i},{d},{s},{r},{e},{si}\n")

print("\nSignals exported to signals.csv\n")
