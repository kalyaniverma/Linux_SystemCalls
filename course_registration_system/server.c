/*
================================================================================================================================
Author: Kalyani Verma
File Description: Server program
================================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "main_menu.h"

#define PORT 8085
#define MAX_CLIENTS 20
#define BUFFER_SIZE 1024


int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pid_t child_pid;

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    
	if(argc != 2){
		printf("Usage: %s <port>\n", argv[0]);
		return EXIT_FAILURE;
	}
    int port = atoi(argv[1]);
    
    // Initialize the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(1);
    }

    printf("Server is listening on port %d...\n", port);

    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket == -1) {
            perror("Accepting client connection failed");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Fork a child process to handle the client
        child_pid = fork();
        if (child_pid < 0) {
            perror("Forking failed");
            close(client_socket);
        } else if (child_pid == 0) {
            // In the child process
            //close(server_socket);  // Close the server socket in the child process
            main_menu(client_socket);
        } else {
            // In the parent process
            close(client_socket);  // Close the client socket in the parent process
        }
    }

    close(server_socket);
    return 0;
}
