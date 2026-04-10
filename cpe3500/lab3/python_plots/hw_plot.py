import matplotlib.pyplot as plt
import numpy as np

w = np.linspace(-10, 10, 2000)

Xa_mag = np.abs(2 * np.cos(w))
Xb_mag = np.abs(2 * np.sin(2 * w))
Xc_mag = np.exp(-2) / np.sqrt(4 + w**2)

plt.figure(figsize=(12, 8))

plt.subplot(3, 1, 1)
plt.plot(w, Xa_mag)
plt.title("|X_a(jω)| = 2|cos(ω)|")

plt.subplot(3, 1, 2)
plt.plot(w, Xb_mag)
plt.title("|X_b(jω)| = 2|sin(2ω)|")

plt.subplot(3, 1, 3)
plt.plot(w, Xc_mag)
plt.title("|X_c(jω)| = e^{-2}/√(4+ω²)")

plt.tight_layout()
plt.show()
