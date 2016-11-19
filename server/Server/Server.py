import socketserver
import signal
import sys
import time

from .RequestHandler import RequestHandler

class Server():
    def __init__(self, hostname, port):
        self.host = hostname
        self.port = port;

        # Socket initialize
        self.server = socketserver.TCPServer((self.host, self.port), RequestHandler)

        signal.signal(signal.SIGINT, self.signal_handler)

    def __del__(self):
        # Free socket
        self.port = self.port

    def signal_handler(self, signal, frame):
        print("Exited")
        self.server.server_close()
        sys.exit(0)

    def loop(self):
        print("Server loop started")
        self.server.serve_forever()