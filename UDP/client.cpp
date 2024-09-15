#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  // Include this header for inet_addr
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serveraddr;
    socklen_t len = sizeof(serveraddr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Prepare server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(PORT);

    while (true) {
        // Get user input
        std::cout << "Enter message to send: ";
        std::cin.getline(buffer, BUFFER_SIZE);

        // Send message to server
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serveraddr, len);

        // Receive acknowledgment from server
        ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&serveraddr, &len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[n] = '\0';

        std::cout << "Server response: " << buffer << std::endl;
    }

    close(sockfd);
    return 0;
}
