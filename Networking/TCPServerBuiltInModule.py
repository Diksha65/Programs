import socket
import sys
import socketserver
import datetime

def request_handler(request_socket):
    try:
        request_msg = request_socket.recv(1024)
        print("received %s" %request_msg)
        request_socket.send('Time %s' %str(datetime.datetime.now()))
        sys.stdout.flush()

    except Exception:
        print('e ')

def simple_tcp_server():
    tcp_server = socketserver.TCPServer(('127.0.0.1',8080),RequestHandlerClass = None, bind_and_activate = True)
    print('This is the server')
    while True:
        request_socket, addr_port_tuple = tcp_server.get_request()
        print('Connection from: %s' %str(addr_port_tuple))

        request_handler(request_socket)
    tcp_server.shutdown_request(request_socket)

if __name__ == "__main__":
    simple_tcp_server()