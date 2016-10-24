/* Server program for a TCP/IP */

#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <sys/unistd.h>
#include<netinet/in.h>


void error(char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char*argv[]){
	
		int sockfd, newsockfd, portno, clilen;
		char buffer[256];
		struct sockaddr_in serv_addr, cli_addr;
		int n;
		
		
		// checking the argument in the command line to check if there is a port provided
		// argc counts the argument in the cmd line to check if the port is provided with the exection of the program.
		
		if (argc < 2){
			fprintf(stderr, "Error, no port provided\n");
			exit(1);
		}
		
		// creating a socket.
		/* AF_INET/ PF_INET -> Internet version 4, TCP -> TCP, 0 is for us creating*/

		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		
		if (sockfd < 0){
		
			error("Error opening socket");	
		}
		
		// Making the serv_addr zero/ null
		
		bzero((char *) &serv_addr, sizeof(serv_addr));
		
		// Converting port no from char to integer a to i.
		
		portno = atoi(argv[1]);
		
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);
		
		// binding the port and socket
		
		if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
			error("Error on binding");
		}
		
		// listening for the socket request
		
		listen(sockfd, 5);
		clilen = sizeof(cli_addr);
		
		// creating a new socket for the client side
		// accepting the socket from the client.
		
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		
		if(newsockfd < 0){
			
			error("Error on accept");
		}
		
		bzero(buffer, 256);
		
		// reading from the buffer
		
		n = read(newsockfd, buffer, 256);
		
		if ( n < 0){

			error("Error reading from socket");
		
		}
		
		// printing the message 
		
		printf("Here is the message: %s\n",buffer);
		
		// writing a reply
		
		n = write(newsockfd,"I got your messge",18);
		
		if ( n < 0){

			error("Error writing to socket");
		
		}	
		
		return 0;
		
} // main