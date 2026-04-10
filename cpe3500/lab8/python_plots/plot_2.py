import csv
import matplotlib.pyplot as plt

n = []
in1 = []
in2 = []
in3 = []

with open("signals.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n.append(int(row["n"]))
        in1.append(float(row["adc_buffer"]))

with open("signals_2.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        # n.append(int(row["n"]))
        # in1.append(float(row["input_signal"]))
        in2.append(float(row["output_freq"]))
        in3.append(float(row["output_fft_mag"]))

fig, axs = plt.subplots(1, 2, sharex=True, sharey=True)

axs[0].plot(in2, in3, label="output_fft_mag", linewidth=1)
axs[0].plot()
# axs[0].xlabel("Hz")
# axs[0].ylabel("Value")
axs[0].set_title("Freq vs FFT Magnitude")
axs[0].legend()
axs[0].grid(True)


axs[1].plot(n, in1, label="input_signal", linewidth=1)
# axs[1].xlabel("N")
# axs[1].ylabel("Value")
axs[1].set_title("Input Magnitude")
axs[1].legend()
axs[1].grid(True)

fig.tight_layout()

plt.show()
