#include <cstring>
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    // Let's check if port number is supplied or not..
    if (argc != 2)
    {
        cerr << "Run program as 'program <port>'\n";
        return -1;
    }

    auto &portNum = argv[1];
    const unsigned int backLog = 8; // number of connections allowed on the incoming queue

    addrinfo hints, *res, *p; // we need 2 pointers, res to hold and p to iterate over
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int gAddRes = getaddrinfo(NULL, portNum, &hints, &res);
    if (gAddRes != 0)
    {
        cerr << gai_strerror(gAddRes) << endl;
        return -2;
    }

    cout << "Detecting addresses\n";

    unsigned int numOfAddr = 0;
    char ipStr[INET6_ADDRSTRLEN]; // ipv6 length makes sure both ipv4/6 addresses can be stored in this variable

    // Now since getaddrinfo() has given us a list of addresses
    // we're going to iterate over them and ask user to choose one
    // address for program to bind to
    for (p = res; p != NULL; p = p->ai_next)
    {
        void *addr;
        string ipVer;

        // if address is ipv4 address
        if (p->ai_family == AF_INET)
        {
            ipVer = "IPv4";
            sockaddr_in *ipv4 = reinterpret_cast<sockaddr_in *>(p->ai_addr);
            addr = &(ipv4->sin_addr);
            ++numOfAddr;
        }

        // if address is ipv6 address
        else
        {
            ipVer = "IPv6";
            sockaddr_in6 *ipv6 = reinterpret_cast<sockaddr_in6 *>(p->ai_addr);
            addr = &(ipv6->sin6_addr);
            ++numOfAddr;
        }

        // convert IPv4 and IPv6 addresses from binary to text form
        inet_ntop(p->ai_family, addr, ipStr, sizeof(ipStr));
        cout << "(" << numOfAddr << ") " << ipVer << " : " << ipStr << endl;
    }

    // if no addresses found :(
    if (!numOfAddr)
    {
        cerr << "Found no host address to use\n";
        return -3;
    }

    // ask user to choose an address
    cout << "Enter the number of host address to bind with: ";
    unsigned int choice = 0;
    bool madeChoice = false;
    do
    {
        cin >> choice;
        if (choice > (numOfAddr + 1) || choice < 1)
        {
            madeChoice = false;
            cout << "Wrong choice, try again!\n";
        }
        else
            madeChoice = true;
    } while (!madeChoice);

    p = res;

    // let's create a new socket, socketFD is returned as descriptor
    // man socket for more information
    // these calls usually return -1 as result of some error
    int sockFD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockFD == -1)
    {
        cerr << "Error while creating socket\n";
        freeaddrinfo(res);
        return -4;
    }

    // Let's bind address to our socket we've just created
    int bindR = bind(sockFD, p->ai_addr, p->ai_addrlen);
    if (bindR == -1)
    {
        cerr << "Error while binding socket\n";

        // if some error occurs, make sure to close socket and free resources
        close(sockFD);
        freeaddrinfo(res);
        return -5;
    }

    // finally start listening for connections on our socket
    int listenR = listen(sockFD, backLog);
    if (listenR == -1)
    {
        cerr << "Error while Listening on socket\n";

        // if some error occurs, make sure to close socket and free resources
        close(sockFD);
        freeaddrinfo(res);
        return -6;
    }

    // structure large enough to hold client's address
    sockaddr_storage client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    const string response = "Hello World";

    // a fresh infinite loop to communicate with incoming connections
    // this will take client connections one at a time
    // in further examples, we're going to use fork() call for each client connection
    while (1)
    {
        // accept call will give us a new socket descriptor
        int newFD = accept(sockFD, (sockaddr *)&client_addr, &client_addr_size);
        if (newFD == -1)
        {
            cerr << "Error while Accepting on socket\n";
            continue;
        }

        // send call sends the data you specify as second param and it's length as 3rd param, also returns how many bytes were actually sent
        auto bytes_sent = send(newFD, response.data(), response.length(), 0);
        close(newFD);
    }

    close(sockFD);
    freeaddrinfo(res);

    return 0;
}
