import csv

import matplotlib.pyplot as plt

n = []
in1 = []
in2 = []
in3 = []

with open("signals_1.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        # n.append(int(row["n"]))
        in1.append(float(row["output_freq"]))
        in2.append(float(row["input_fft_mag"]))

plt.plot(in1, in2, label="input_fft_mag", linewidth=1)
plt.legend()
plt.grid(True)

plt.show()
