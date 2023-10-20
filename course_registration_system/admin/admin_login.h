/*
================================================================================================================================
Author: Kalyani Verma
File Description: Admin authentication
================================================================================================================================
*/



#include "admin.h"

#define PORT 8085
#define BUFFER_SIZE 1024


int admin_login(int client_socket){

    char message[300];
    int bytes_received;
    char username[20] ;
    char password[20] ;


    //admin sign in for username
    
    printf("Entering Admin Credentials...\n");
    strcpy(message, "Sign in for Admin:\nEnter Username: ");
    send(client_socket, message, strlen(message), 0);

    bzero(username, sizeof(username));
    bytes_received = recv(client_socket, username, sizeof(username), 0);
    
    //replacing the \n with \0 to avoid garbage value
    username[bytes_received] = '\0';
    
    printf("Username: %s\n", username);

    //admin sign in for password
    send(client_socket, "Password: ", strlen("Password: "), 0);

    bzero(password, sizeof(password));
    bytes_received = recv(client_socket, password, sizeof(password), 0);
    
    //replacing the \n with \0 to avoid garbage value
    password[bytes_received] = '\0';

    printf("Password: %s\n", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
    
    	printf("Admin logged in successfully\n");
        admin(client_socket);
        
    }
    
    else
    	printf("Invalid Credentials!\n");

    //close(client_socket);
    return 0;
}
