import socket
import sys

def get_constants(PREFIX):
    return dict( (getattr(socket, n), n) for n in dir(socket) if n.startswith(PREFIX))

families = get_constants('AF_')
types = get_constants('SOCK_')
protocols = get_constants('IPPROTO_')

sock = socket.create_connection(('localhost', 10000))

print('Family :', families[sock.family])
print('Types :', types[sock.type])
print('Protocols :', protocols[sock.proto])

try:
    message = b'This is the message. It will be repeated'
    print('sending %s' %message)
    sock.sendall(message)

    amount_received = 0
    amount_expected = len(message)

    while amount_received < amount_expected:
        data = sock.recv(16)
        amount_received += len(data)
        print('Receoved %s' %data)
    
finally:
    print('closing socket')
    sock.close()


