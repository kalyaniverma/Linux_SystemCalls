/*
================================================================================================================================
Author: Kalyani Verma
File Description: Display Main Menu of Course Registration System
================================================================================================================================
*/



#include "admin/admin_login.h"
#include "faculty/faculty_login.h"
#include "student/student_login.h"


void main_menu(int client_socket) {
	
	char message[1024];
	int bytes_received;
	
	while (1) {
    
        	//sending menu to the client
        	char main_menu[] = "Login as:\n\t1. Admin\n\t2. Faculty\n\t3. Student\n\tTo quit, press q\nChoice: ";
        	send(client_socket, main_menu, sizeof(main_menu), 0);

		// Receive the client's choice
		bzero(message, sizeof(message)); // to clear the buffer to receive data properly
		bytes_received = recv(client_socket, message, sizeof(message), 0);

		//replacing the \n with \0 in the read_buffer to avoid garbage value
		message[bytes_received] = '\0';

		if(message[0] == '1') admin_login(client_socket);
		        
		else if(message[0] == '2') faculty_login(client_socket);
		
		else if(message[0] == '3') student_login(client_socket);
		
		else if(message[0] == 'q') exit(0);
		
		else {
			char response[] = "Invalid choice. Please select a valid option.\n";
			send(client_socket, response, sizeof(response), 0);
			break;
		}

	}
        close(client_socket);

}
