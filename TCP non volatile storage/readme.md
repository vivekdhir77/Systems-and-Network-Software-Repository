# TCP File Sender Client

This C program implements a basic TCP client that connects to a server and sends the contents of a file named `send.txt` to the server.

## Features

- **TCP Connection:** Connects to a TCP server on port 8080.
- **File Sending:** Reads data from `send.txt` and sends it to the server.
- **Error Handling:** Includes basic error handling for socket creation, file operations, and data transmission.

## Compilation

To compile the program, use the following command:

```sh
gcc -o tcp_client TCP_client.c
gcc -o tcp_server TCP_server.c

./tcp_server

./tcp_client
```