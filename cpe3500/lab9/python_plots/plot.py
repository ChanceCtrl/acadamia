import csv

import matplotlib.pyplot as plt

n = []
adc = []
dac = []

with open("signals.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n.append(int(row["n"]))
        adc.append(int(row["adc_buffer_40k"]))
        dac.append(int(row["dac_buffer_40k"]))

plt.figure(figsize=(10, 5))

# plt.plot(n, adc, label="Unprocessed Buffer", linewidth=1)
plt.plot(n, dac, label="Processed Buffer", linewidth=1)

plt.xlabel("Sample Index")
plt.ylabel("Value")
plt.title("Processed over N Sample")
plt.ylim([500, 4000])
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
