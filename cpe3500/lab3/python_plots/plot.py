import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("signals.csv")

plt.figure()
plt.plot(df["n"], df["step"], label="Shifted step")
plt.plot(df["n"], df["expon"], label="Shifted expon")
plt.plot(df["n"], df["sinus"], label="Shifted sinus")

plt.xlabel("n")
plt.ylabel("Amplitude")
plt.title("DSP Signals from STM32 RAM")
plt.legend()
plt.grid()
plt.show()
