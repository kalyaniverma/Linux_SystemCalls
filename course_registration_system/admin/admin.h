/*
================================================================================================================================
Author: Kalyani Verma
File Description: Display admin menu
================================================================================================================================
*/

#include "admin_student.h"
#include "admin_faculty.h"


#define PORT 8085
#define BUFFER_SIZE 1024



int admin(int client_socket){
    

    char message[BUFFER_SIZE];
    int bytes_received;
    
    char menu[] = "\n\n=============== Welcome to Admin Menu ===============\nEnter the Option:\n1. Add Student\n2. Add Faculty\n3. Activate Student\n4. Decativate Student\n5. Update Student Details\n6. Update Faculty Details\n7. View Student\n8. View Faculty\n9. Logout\n";
        send(client_socket, menu, sizeof(menu), 0);

    while (1) {
    
        
        
        
        bzero(message, sizeof(message));
        bytes_received = recv(client_socket, message, sizeof(message), 0);
        if (bytes_received <= 0) {
            perror("Client disconnected");
            break;
        }

        message[bytes_received] = '\0';


        switch (message[0]) {
            case '1': {
            
		add_student(client_socket);
                char response[] = "\nAdded Student.\n\nEnter the Option:\n1. Add Student\n2. Add Faculty\n3. Activate Student\n4. Decativate Student\n5. Update Student Details\n6. Update Faculty Details\n7. View Student\n8. View Faculty\n9. Logout\n";
                send(client_socket, response, sizeof(response), 0);
                
                break;
            }
            
            case '2': {
                add_faculty(client_socket);
                char response[] = "Added Faculty.\n\nEnter the Option:\n1. Add Student\n2. Add Faculty\n3. Activate Student\n4. Decativate Student\n5. Update Student Details\n6. Update Faculty Details\n7. View Student\n8. View Faculty\n9. Logout\n";
                send(client_socket, response, sizeof(response), 0);
                break;
            }
            
            case '3': {
                // Activate Student functionality
                // Implement this functionality here, including data storage
                printf("Activating the student...\n");
                activate_student(client_socket);
                
                break;
            }
            case '4': {
                // Deactivate Student functionality
                // Implement this functionality here, including data storage
                printf("Deactivating the student...\n");
                deactivate_student(client_socket);
                break;
            }
            case '5': {
                // Update Details functionality
                // Implement this functionality here, including data storage
                printf("Updating Student...\n");
                update_student(client_socket);
                break;
            }
            case '6': {
                
                printf("Updating Faculty...\n");
                update_faculty(client_socket);
                break;
            }
            case '7': {
            	
            	printf("Viewing Student details...\n");
                view_students(client_socket);
                break;
            }
            case '8': {
            
                printf("Viewing Faculty details...\n");
                view_faculty(client_socket);
                break;
            }
            case '9': {
            
                return 0;
                break;
                
            }
            default: {
                send(client_socket, "Invalid choice. Please select a valid option.\n", sizeof("Invalid choice. Please select a valid option.\n"), 0);
                break;
            }
        }
        
    }
        
        return 0;
   

}

