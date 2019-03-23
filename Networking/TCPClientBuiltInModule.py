import socket
s = socket.socket()
s.connect(('127.0.0.1', 8080))
s.send(b'hello')
msg = s.recv(1024)
print(msg)