import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 9999)
print('connecting to %s on port %s' %server_address)
sock.connect(server_address)

while True:
    try:
        message = input('You: ').encode()
        sock.sendall(message)
        data = sock.recv(1024)
        print('Server: %s' %(data.decode()))
    except KeyboardInterrupt:
        sock.close()

