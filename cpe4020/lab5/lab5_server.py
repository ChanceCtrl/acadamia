import socket
import time

print("Hello, World!")

localAddr = "40.20.3.42"
port = 8080

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((localAddr, port))
server_socket.listen(1)

while True:
    print("Waiting for a connection...")
    client_socket, client_address = server_socket.accept()
    print("Data received!")
    try:
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            rxdata = data.decode("utf-8")
            capitalized_data = data.decode("utf-8").upper()
            client_socket.sendall(capitalized_data.encode("utf-8"))
            print(f"Received: {rxdata}")
            print("Data sent!")

    finally:
        client_socket.close()
