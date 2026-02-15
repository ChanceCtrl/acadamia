from pygdbmi.gdbcontroller import GdbController
import struct
import matplotlib.pyplot as plt

# ---------------------------
# Config
# ---------------------------
N = 20
OPENOCD_GDB_PORT = 3333  # OpenOCD GDB server port
ELF_FILE = "../build/Lab2.elf"  # Path to your compiled STM32 ELF


# ---------------------------
# Helper functions
# ---------------------------
def get_symbol_address(gdbmi, symbol_name):
    """Query GDB for the address of a symbol."""
    resp = gdbmi.write(f"p &{symbol_name}")
    try:
        addr_str = resp[0]["payload"].split("=")[1].strip().split()[0]
        return int(addr_str, 16)
    except Exception as e:
        raise RuntimeError(f"Failed to get address for {symbol_name}: {resp}") from e


def read_int_array(gdbmi, addr, length):
    """Read 'length' 32-bit integers from target memory"""
    result = []
    for i in range(length):
        mem_addr = addr + i * 4
        response = gdbmi.write(f"x/wx 0x{mem_addr:X}")
        val_str = response[0]["payload"].split(":")[1].strip()
        result.append(int(val_str, 16))
    return result


def read_float_array(gdbmi, addr, length):
    """Read 'length' 32-bit floats from target memory"""
    result = []
    for i in range(length):
        mem_addr = addr + i * 4
        response = gdbmi.write(f"x/wx 0x{mem_addr:X}")
        val_str = response[0]["payload"].split(":")[1].strip()
        word = int(val_str, 16)
        result.append(struct.unpack("<f", struct.pack("<I", word))[0])
    return result


# ---------------------------
# Main
# ---------------------------
def main():
    # Start GDB controller (older API, no gdb_path or gdb_args)
    gdbmi = GdbController()  # just default constructor

    # Load your ELF manually
    gdbmi.write(f"file {ELF_FILE}")

    # Connect to OpenOCD GDB server
    gdbmi.write(f"target remote localhost:{OPENOCD_GDB_PORT}")

    # Halt MCU safely
    gdbmi.write("monitor reset halt")

    # Get addresses dynamically from symbols
    addr_delta = get_symbol_address(gdbmi, "delta")
    addr_step = get_symbol_address(gdbmi, "step")
    addr_rect = get_symbol_address(gdbmi, "rect")
    addr_sinus = get_symbol_address(gdbmi, "sinus")

    # Read memory
    delta = read_int_array(gdbmi, addr_delta, N)
    step = read_int_array(gdbmi, addr_step, N)
    rect = read_int_array(gdbmi, addr_rect, N)
    sinus = read_float_array(gdbmi, addr_sinus, N)

    n = list(range(N))

    # Plot
    plt.figure(figsize=(10, 6))
    plt.subplot(2, 2, 1)
    plt.stem(n, delta)
    plt.title("Unit Impulse")

    plt.subplot(2, 2, 2)
    plt.stem(n, step)
    plt.title("Unit Step")

    plt.subplot(2, 2, 3)
    plt.stem(n, rect)
    plt.title("Rectangular")

    plt.subplot(2, 2, 4)
    plt.stem(n, sinus)
    plt.title("Sinusoidal")

    plt.tight_layout()
    plt.show()

    gdbmi.exit()


if __name__ == "__main__":
    main()
