#include <cstring>
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    // Now we're taking an ipaddress and a port number as arguments to our program
    if (argc != 3)
    {
        cerr << "Run program as 'program <ipaddress> <port>'\n";
        return -1;
    }

    auto &ipAddress = argv[1];
    auto &portNum = argv[2];

    addrinfo hints, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int gAddRes = getaddrinfo(ipAddress, portNum, &hints, &p);
    if (gAddRes != 0)
    {
        cerr << gai_strerror(gAddRes) << endl;
        return -2;
    }

    if (p == NULL)
    {
        cerr << "No addresses found\n";
        return -3;
    }

    // socket() call creates a new socket and returns it's descriptor
    int sockFD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockFD == -1)
    {
        cerr << "Error while creating socket\n";
        return -4;
    }

    // connect() call tries to establish a TCP connection to the specified server
    int connectR = connect(sockFD, p->ai_addr, p->ai_addrlen);
    if (connectR == -1)
    {
        close(sockFD);
        cerr << "Error while connecting socket\n";
        return -5;
    }

    string reply(15, ' ');

    // recv() call tries to get the response from server
    // BUT there's a catch here, the response might take multiple calls
    // to recv() before it is completely received
    // will be demonstrated in another example to keep this minimal
    auto bytes_recv = recv(sockFD, &reply.front(), reply.size(), 0);
    if (bytes_recv == -1)
    {
        cerr << "Error while receiving bytes\n";
        return -6;
    }

    cout << "\nClient recieved: " << reply << endl;
    close(sockFD);
    freeaddrinfo(p);

    return 0;
}
