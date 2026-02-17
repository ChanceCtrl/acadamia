import socket

HOST = "40.20.3.33"  # Server's hostname or IP address
PORT = 8080  # Port to connect to

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to the server
    client_socket.connect((HOST, PORT))
    print(f"CONNECTED TO: {HOST}:{PORT}")

    # Send a message to the server
    client_socket.sendall(b"I am Chuck Norris!")

    # Receive data from the server
    data = client_socket.recv(1024)
    print(f"DATA: {data.decode()}")

finally:
    # Close the connection
    client_socket.close()
    print("Connection closed")
