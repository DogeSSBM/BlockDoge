#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void server(void)
{
    int port = 1234;
    int sockfd;
    struct sockaddr_in si_me, si_other;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&si_me, '\0', sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr*)&si_me, sizeof(si_me));
    addr_size = sizeof(si_other);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)& si_other, &addr_size);
    printf("[+]Data Received: %s", buffer);
}

void client(void)
{
    int port = 1234;
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer, "Hello Server\n");
    sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("[+]Data Send: %s", buffer);
}

int main(int argc, char **argv)
{
    if(argc == 2 && strcmp(argv[1], "client") == 0){
        client();
    }else if(argc == 2 && strcmp(argv[1], "server") == 0){
        server();
    }else{
        fprintf(stderr, "Usage:\n\t%s <client|server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}

// #include "Includes.h"
//
// int main(int argc, char **argv)
// {
//
//     return 0;
// }
