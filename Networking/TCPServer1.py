import sys
import socketserver

class MyTCPHandler(socketserver.BaseRequestHandler):

    def handle(self):
        self.data = self.request.recv(1024)
        print('Client: ', self.data)
        msg = input('You: ').encode()
        self.request.sendall(msg)

if __name__ == "__main__":
    HOST, PORT = 'localhost', 9999
    server = socketserver.TCPServer((HOST, PORT), MyTCPHandler)
    server.serve_forever()
