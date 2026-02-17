import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("signals.csv")

plt.figure()
# plt.stem(df["n"], df["sine2"], label="Composite")
plt.stem(df["n"], df["sine3"], label="Filtered", linefmt="r")
plt.stem(df["n"], df["sine1"], label="Pure 5hz", linefmt="g")

plt.xlabel("n")
plt.ylabel("Amplitude")
plt.title("DSP Signals from STM32 RAM")
plt.legend()
plt.grid()
# plt.xticks(range(0, 41, 1))
# plt.yticks([x / 10 for x in range(-30, 40, 5)])
plt.show()
