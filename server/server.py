from Server import Server

if __name__ == "__main__":
    # In Future getting hostname and port from cmd args
    # Initialize server with hostname and port
    server = Server.Server("localhost", 9999)

    # Activate the server; it will keep running until
    # interrupt the app with Ctrl-C
    server.loop()