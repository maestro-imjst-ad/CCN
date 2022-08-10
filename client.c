#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<netdb.h>
#define BUFLEN 9000

int main() {

    char buf[BUFLEN];
    struct sockaddr_in sin;

    int sock_descriptor= socket(AF_INET, SOCK_STREAM,0);
    bzero(&sin,sizeof(sin));

    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=inet_addr("127.0.0.1");   /* convert a string dotted decimal IP4 address to a NETWORK BYTE ORDERED 32 bit value*/ 
    sin.sin_port=htons(8000);

    connect(sock_descriptor,(struct sockaddr *) &sin, sizeof(sin));

    printf("\n Enter the data to be sent to the server \n");
    fgets(buf,sizeof(buf),stdin);

    send(sock_descriptor,buf,sizeof(buf),0); /* Sends data to the socket. The socket must be
    connected to a remote socket. The optional flags
    argument has the same meaning asor recv() 
    above. Returns the number of bytes sent */
    close(sock_descriptor);
    exit(0);
}
