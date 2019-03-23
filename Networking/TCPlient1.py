import socket
import sys

HOST, PORT = "localhost", 9999
data = input("You: ").encode()

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((HOST,PORT))
while True:
    try:
        sock.sendall(data)
        received = sock.recv(1024)
        print("Server: {}".format(received))

    finally:
        sock.close()

