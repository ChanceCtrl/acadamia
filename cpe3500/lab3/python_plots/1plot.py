import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("signals.csv")

plt.figure()
plt.stem(df["n"], df["system2"], label="system2", linefmt="g")

plt.xlabel("n")
plt.ylabel("Amplitude")
plt.title("DSP Signals from STM32 RAM")
plt.legend()
plt.grid()
plt.xticks(range(0, 20, 1))
# plt.yticks([x / 10 for x in range(0, 20, 5)])
plt.show()
