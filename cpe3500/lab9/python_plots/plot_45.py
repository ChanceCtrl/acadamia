import csv

import matplotlib.pyplot as plt

n = []
in1 = []
in2 = []
in3 = []

with open("signals_4.csv", "r") as f:
    reader = csv.DictReader(f)
    i = 0
    for row in reader:
        i = i + 1
        # n.append(int(row["n"]))
        in1.append(float(row["output_freq"]))
        in2.append(float(row["input_fft_mag"]))
        in3.append(float(row["filtered_fft_mag"]))

        if i > 1024:
            break

plt.plot(in1, in2, label="input_fft_mag", linewidth=1)
plt.legend()
plt.grid(True)

plt.show()

plt.plot(in1, in3, label="filtered_fft_mag", linewidth=1)
plt.legend()
plt.grid(True)

plt.show()
