#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 

#define PORT 5555

int main(void)
{
    int s, s2;
    socklen_t len;
    struct sockaddr_in local, remote;
    char str[100];

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("socket creation failed…");
        exit(1);
    }

    bzero((char *)&local, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_port = htons(PORT);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr *)&local, sizeof(local)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(s, 5) == -1) {
        perror("listen failed");
        exit(1);
    }

    for(;;) {
        int done, n;
        printf("Waiting for a connection...\n");
        len = sizeof(remote);  // Correct length variable to socklen_t
        if ((s2 = accept(s, (struct sockaddr *)&remote, &len)) == -1) {
            perror("accept failed");
            exit(1);
        }

        printf("Connected.\n");

        done = 0;
        do {
            n = recv(s2, str, sizeof(str), 0);
            if (n <= 0) {
                if (n < 0) perror("recv failed");
                done = 1;
            } else {
                str[n] = '\0';  // Null-terminate the received string
                printf("serverecho> %s\n", str);  // Fix printf usage
            }

            if (!done) {
                if (send(s2, str, n, 0) < 0) {
                    perror("send failed");
                    done = 1;
                }
            }
        } while (!done);

        close(s2);
    }

    close(s);
    return 0;
}
