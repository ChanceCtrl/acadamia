import gdb

N = 2048

# Resolve addresses
in1 = int(gdb.parse_and_eval("&input_signal"))
in2 = int(gdb.parse_and_eval("&output_freq"))
in3 = int(gdb.parse_and_eval("&output_fft_mag"))


def read_u16(addr):
    return int(gdb.parse_and_eval(f"*(unsigned short *)0x{addr:X}"))


def read_f32(addr):
    return float(gdb.parse_and_eval(f"*(float *)0x{addr:X}"))


def export_signals():
    with open("signals_2.csv", "w") as f:
        f.write("n,input_signal,output_freq,output_fft_mag\n")

        for i in range(N):
            a = read_f32(in1 + i * 4)
            b = read_f32(in2 + i * 4)
            c = read_f32(in3 + i * 4)

            f.write(f"{i},{a},{b},{c}\n")

    print("\nSignals exported to signals.csv\n")


export_signals()
