#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd, (const sockaddr *)&addr, sizeof(addr));

    // Send data to the server
    char message[] = "Hello, world!";
    send(sockfd, message, strlen(message), 0);

    // Receive data from the server
    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Print the data from the server
    std::cout << buffer << std::endl;

    // Close the sockets
    close(sockfd);

    return 0;
}
