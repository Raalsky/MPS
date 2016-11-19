import sys

from Client import Client

if __name__ == "__main__":
    # App arguments merged to one line
    data = " ".join(sys.argv[1:])

    # Create client app
    client = Client.Client("localhost", 9999)

    # Let client send data to server
    client.send(data)