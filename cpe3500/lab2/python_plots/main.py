import numpy as np
import matplotlib.pyplot as plt


def main():
    start = 0x20000120
    end = 0x20000170

    data = np.fromfile("mem.bin", dtype=np.uint32)

    addrs = np.arange(start, start + 4 * len(data), 4)

    plt.plot(addrs, data, marker="o")
    plt.xlabel("Address (hex)")
    plt.ylabel("Value (uint32)")
    plt.title("Memory dump from 0x20000120 to 0x20000170")
    plt.grid(True)

    plt.show()


if __name__ == "__main__":
    main()
