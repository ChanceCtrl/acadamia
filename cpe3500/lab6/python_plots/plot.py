import csv
import matplotlib.pyplot as plt

n = []
adc = []
dac = []

with open("signals.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        n.append(int(row["n"]))
        adc.append(int(row["adc_buffer"]))
        dac.append(int(row["dac_buffer"]))

plt.figure(figsize=(10, 5))

plt.plot(n, adc, label="ADC Buffer", linewidth=1)
plt.plot(n, dac, label="DAC Buffer", linewidth=1)

plt.xlabel("Sample Index")
plt.ylabel("Value")
plt.title("ADC vs DAC Signals")
plt.ylim([2050, 4500])
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
