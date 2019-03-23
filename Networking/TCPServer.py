import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 9999)
print('starting on %s port %s' %server_address)
sock.bind(server_address)

sock.listen(1)
print('waiting for a connection')
connection, client_address = sock.accept()

while True:
    try:
        data = connection.recv(100)
        print('Client: %s' %(data.decode()))
        message = input('You: ').encode()
        if message:
            connection.sendall(message)
        else:
            print('no more data from the client')
            break
    except KeyboardInterrupt:
        connection.close()
    
