import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("data.csv")

plt.figure()
plt.plot(df["time"], df["temp"])

plt.xlabel("Time in seconds")
plt.ylabel("Temp in Celcius")
plt.grid()
plt.show()
