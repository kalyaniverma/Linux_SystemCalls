/*
=======================================================================================================================================
Name : 34b.c
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
#include <pthread.h>

void *talkToClient(void *client_sock_ptr)
{
    	int client_sock = *((int *)client_sock_ptr);
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
    	pthread_exit(NULL);
    	close(client_sock);
}
int main()
{
    	//server and client are on same machine so we use local host ip 127.0.0.1 and any port > 5000
    
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
     
     
    	while (1) {
        	struct sockaddr_in client_addr;
        	int client_sock;
        	socklen_t client_addr_len = sizeof(client_addr);

        	client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        	if (client_sock == -1) {
            		perror("accept");
            		continue;
        	}

        	pthread_t thread_id;
        	if (pthread_create(&thread_id, NULL, talkToClient, &client_sock) != 0) {
            		perror("pthread_create");
            		close(client_sock);
        	}
    	}


    	close(server_sock);
     	return 0;
}
