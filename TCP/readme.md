# Simple TCP Client-Server Application

This project demonstrates a basic TCP client-server application using C. The server listens on a specified port and waits for incoming connections, while the client connects to the server and allows the user to send and receive messages. The server echoes back the messages sent by the client.

## Features
- TCP connection between client and server.
- Server echoes back the received messages.
- Simple interactive communication between client and server.

## Requirements
- Linux (or any POSIX-compliant system)
- GCC (GNU Compiler Collection)


## instructions to run

gcc Server_TCP.c -o server
./server


gcc Client_TCP.c -o client
./client  127.0.0.1