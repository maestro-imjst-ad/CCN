#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#define BUFLEN 9000

int main()
{          
    char buf[BUFLEN];
	struct sockaddr_in sin;
	
	int sock_descriptor= socket(AF_INET, SOCK_STREAM,0);
	bzero(&sin,sizeof(sin));

	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr= INADDR_ANY;
	sin.sin_port=htons(8000); /* Converts16-bit positive integers from host to network byte order */
	
    bind(sock_descriptor,(struct sockaddr *)&sin, sizeof(sin));
	listen(sock_descriptor, 4);

	int temp_sock_descriptor= accept(sock_descriptor, NULL, NULL);

	recv(temp_sock_descriptor,buf,sizeof(buf),0); /* Receives data from the socket. The
                                                                                            return value is a string representing the 
                                                                                            data received. The maximum amount of 
                                                                                            data to be received at once is specified                                                                   by bufsize */
    printf("\n data received\n");
	puts(buf);
	close(temp_sock_descriptor);
	exit(0);
	
}
