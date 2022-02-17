#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;



int main() {

// @TODO Create a socket

    // socket(int __domain, int __type, int __protocol) : int
    // AF_INET for IPv4 is Address Family used to designate the type of addresses that the socket can communicate with
    // SOCK_STREAM for TCP 
    // 0 to let networking stack figure out it self
    int listeningSocket = socket(AF_INET, SOCK_STREAM, 0); 

    if (listeningSocket == -1) { 
        cerr << "Can't create a socket!";
        return -1;
    }


// @TODO Bind the socket to IP port
    
    sockaddr_in hint; //sockaddr_in for ipv4, sockaddr_in6 for ipv6 

    hint.sin_family = AF_INET; // sin_family is the AF for the transport address, always be set to AF_INET

    hint.sin_port = htons(54000); // transport protocol port #. htons = hostshort

    //inet_pton converts IPv4 and IPv6 addresses from text to binary form
    // 0.0.0.0 to get any addr
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); 


    // Test binding
    if (bind(AF_INET, &hint, sizeof(hint)) == -1) 
    {
        cerr << "Can't bind to IP/port";
        return -2;
    }


    // Mark the socket for listening in
    // Accept a call
    //Close the listen socket
    //While receiving display messace, echo message
    // Close socket

    return 0;
}
