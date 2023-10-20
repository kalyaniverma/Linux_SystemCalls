/*
=======================================================================================================================================
Name : 34a.c
Author : Kalyani Verma
Description : Write a program to create a concurrent server.
		a. use fork
		b. use pthread_create
Date: 11th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

void talkToClient(int  client_sock)
{
	char buffer[1024];
    	bzero(buffer,1024);
    	int f=recv(client_sock,buffer,sizeof(buffer),0);
    	printf("addde = %d\n",f);
    	printf("Client : %s \n",buffer);
    
    	bzero(buffer,1024);
    	printf("Msg To Client :\n");
    	read(0,&buffer,sizeof(buffer));
    	printf("Server : %s \n",buffer);
    
    	send(client_sock,buffer,sizeof(buffer),0);
    
    	close(client_sock);
}


int main() {
    
    	//server and client are on same machine so we use local host ip 127.0.0.1 and any port > 5000
    	printf("using fork\n");
    	char *ip="127.0.0.1";
    	int port=8085; 
    	int client_sock,server_sock;
    
    	struct sockaddr_in server_addr,client_addr;
    	socklen_t addr_size;
    	char buffer[1024];
    	int n;
    
    	server_sock =socket(AF_INET,SOCK_STREAM,0);
    	if(server_sock < 0)
    	{
      	perror("[-] Error In Socket Creation ");
      	exit(1);
    	}
    	printf("[+] Socket Is Created \n");
    
    
    	memset(&server_addr,'\0',sizeof(server_addr));
    	server_addr.sin_family =AF_INET; //IP version 4
    	server_addr.sin_port=port;
    	server_addr.sin_addr.s_addr=inet_addr(ip);
    
    	//bind ip to port
     	n= bind(server_sock, (struct sockaddr*)&server_addr,sizeof(server_addr));
     
     	if(n<0){
     	perror("[-] Error In Binding");
     	exit(1);
     	}
     	printf("[+] Bindig Successfull  to Port : %d!! \n",port);
     
     	//listen
     
     	listen(server_sock,5);
     	printf("Listening....!\n");
     
     
     	while(1){
     
     		addr_size = sizeof(client_addr);
     
     		client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);
     		printf("[+] client is connected ...\n");
      
    		switch(fork()) {
			case -1: {
				printf("Error in fork.\n");
	            		break;
	        	}
	        	case 0: {
	            		close(server_sock);
	            		talkToClient( client_sock);
	            		exit(1);
	            		break;
	        	}
	        	default: {
	            		close( client_sock);
	            		break;
			}
    
    
     		}
     	}
    	close(server_sock);
     	return 0;
}
