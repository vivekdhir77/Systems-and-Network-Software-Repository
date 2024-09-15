// udp_server.cpp
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len = sizeof(clientaddr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Prepare server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    while (true) {
        // Receive message from client
        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&clientaddr, &len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';

        std::cout << "Received: " << buffer << std::endl;

        // Send acknowledgment back to client
        const char* ack = "Message received";
        sendto(sockfd, ack, strlen(ack), 0, (struct sockaddr*)&clientaddr, len);
    }

    close(sockfd);
    return 0;
}
