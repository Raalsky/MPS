import socket

class Client():
    def __init__(self, hostname, port):
        self.host = hostname
        self.port = port

        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def send(self, data):
        try:
            self.socket.connect((self.host, self.port))
            self.socket.sendto(data.encode('utf-8'), (self.host, self.port))

            received = self.socket.recv(1024)

            print("Sent:     {}".format(data))
            print("Received: {}".format(received))
        finally:
            self.socket.close()