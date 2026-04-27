import csv

import matplotlib.pyplot as plt

file_name = "signals_3.csv"
things_to_plot = ["n", "input_signal", "filtered_signal"]


n = []
in1 = []
in2 = []

with open(file_name, "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n.append(int(row["n"]))
        in1.append(float(row["input_signal"]))
        in2.append(float(row["filtered_signal"]))


plt.plot(n, in2, label="filtered_signal", linewidth=1)
plt.legend()
plt.grid(True)

plt.show()
