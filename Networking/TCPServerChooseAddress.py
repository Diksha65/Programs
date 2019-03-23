import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_name = sys.argv[1]
server_address = (server_name, 10000)
print('starting on %s port %s' %server_address)
sock.bind(server_address)

sock.listen(1)

while True:
    print('waiting for connection')
    connection , client_address = sock.accept()

    try:
        print('client_connecteed: ', client_address)
        while True:
            data = connection.recv(16)
            print('received: %s'%data)
            if data:
                connection.sendall(data)
            else:
                break
    finally:
        connection.close()
        

