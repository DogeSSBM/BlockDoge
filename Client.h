#ifndef CLIENT_H

void client(void)
{
    int port = 2468;
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer, "Hello Server\n");
    sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("[+]Data Send: %s", buffer);
}

#endif /* end of include guard: CLIENT_H */
