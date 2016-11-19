import socketserver

class RequestHandler(socketserver.BaseRequestHandler):
    """
        The mistic part of Server
    """

    def handle(self):
        # self.request is object represent TCP socket connected
        self.data = self.request.recv(1024).strip()

        print("{} wrote: ".format(self.client_address[0]))
        print(self.data)

        self.request.sendall(self.data.upper())
