import csv

import matplotlib.pyplot as plt
import numpy as np

Fs = 20000  # 20 kHz sampling rate

adc = []
dac = []

with open("signals.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        adc.append(int(row["adc_buffer_40k"]))
        dac.append(int(row["dac_buffer_40k"]))

adc = np.array(adc, dtype=float)
dac = np.array(dac, dtype=float)

# Get Time
N = len(adc)
time = np.arange(N) / Fs

# Remove DC offset
adc = adc - np.mean(adc)
dac = dac - np.mean(dac)


def calculate_fft(signal, fs):
    N = len(signal)
    fft_vals = np.fft.fft(signal)
    freqs = np.fft.fftfreq(N, 1 / fs)

    half = N // 2
    return freqs[:half], np.abs(fft_vals[:half])


plt.figure()
plt.plot(time, adc, linewidth=1)
plt.grid(True)
plt.xlabel("Time [sec.]")
plt.ylabel("Amplitude")
plt.title("Captured Audio Signal (Original)")

# FFT original
freq, spectrum = calculate_fft(adc, Fs)

plt.figure()
plt.plot(freq, spectrum, linewidth=1)
plt.grid(True)
plt.xlabel("Frequency [Hz]")
plt.ylabel("Magnitude")
plt.title("Frequency Response of Original Signal")

dac_trim = dac[2:]
time_trim = time[2:]

plt.figure()
plt.plot(time_trim, dac_trim, linewidth=1)
plt.grid(True)
plt.xlabel("Time [sec.]")
plt.ylabel("Amplitude")
plt.title("Captured Audio Signal with Alien Effect")

# FFT processed
freq2, spectrum2 = calculate_fft(dac_trim, Fs)

plt.figure()
plt.plot(freq2, spectrum2, linewidth=1)
plt.grid(True)
plt.xlabel("Frequency [Hz]")
plt.ylabel("Magnitude")
plt.title("Frequency Response (Alien Effect)")

plt.show()
