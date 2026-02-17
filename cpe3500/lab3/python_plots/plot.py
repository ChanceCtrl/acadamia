import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("signals.csv")

plt.figure()
plt.plot(df["n"], df["rect"], label="rect")
plt.plot(df["n"], df["system1"], label="system1")

plt.xlabel("n")
plt.ylabel("Amplitude")
plt.title("DSP Signals from STM32 RAM")
plt.legend()
plt.grid()
plt.xticks(range(0, 20, 1))
plt.yticks([x / 10 for x in range(0, 20, 5)])
plt.show()
