import csv

import matplotlib.pyplot as plt

n = []
in1 = []

with open("signals.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n.append(int(row["n"]))
        in1.append(float(row["adc_buffer"]))

plt.figure(figsize=(10, 5))

plt.plot(n, in1, label="Input 1", linewidth=1)

plt.xlabel("Sample Index")
plt.ylabel("Value")
plt.title("ADC vs DAC Signals")
plt.xlim([0, 2048])
plt.ylim([-2, 2])
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
