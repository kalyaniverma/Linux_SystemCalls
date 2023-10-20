/*
================================================================================================================================
Author: Kalyani Verma
File Description: Display faculty menu
================================================================================================================================
*/


#include "faculty_manage.h"

int faculty_menu(char id[], int client_socket){
    char menu[] = "\n\n=============== Welcome to Faculty Menu ===============\nEnter the Option:\n1. View Offering courses\n2. Add New Course\n3. Remove course from catalog\n4. Update Course Details\n5. Change password\n6. Logout\n";
    send(client_socket, menu, sizeof(menu), 0);

    char buffer[BUFFER_SIZE];

    while (1) {

        bzero(buffer, sizeof(buffer));
        int n = recv(client_socket, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            perror("Client disconnected");
            break;
        }

        if (strchr(buffer, '\n') != NULL) {
            buffer[strlen(buffer) - 1] = '\0';
        }

        int choice = atoi(buffer);

        switch (choice) {
            case 1: {

                view_offering_course(id, client_socket);
                break;
            }
            case 2: {
                // Add Course functionality
                // Implement this functionality here, including data storage
                add_course(id, client_socket);
                char response[] = "Added Course.\n\nEnter the Option:\n1. View Offering courses\n2. Add New Course\n3. Remove course from catalog\n4. Update Course Details\n5. Change password\n6. Logout\n";
                send(client_socket, response, sizeof(response), 0);
                break;
            }
            case 3: {
                // Activate Course functionality
                // Implement this functionality here, including data storage
                remove_course(id, client_socket);
                break;
            }
            case 4: {
                update_course(id, client_socket);
                break;
            }
            case 5: {
                // Update Details functionality
                // Implement this functionality here, including data storage
                change_password1(id, client_socket);
                char response[] = "password changed.\n\n";
                
                strcat(response, menu2);
                
                send(client_socket, response, sizeof(response), 0);
                
                break;
            }
            
            case 6: {
                // Logout functionality
                // char response[] = "Logged out.\n";
                // send(client_socket, response, sizeof(response), 0);
                return 0;
            }
            default: {
                char response[] = "Invalid choice. Please select a valid option.\n";
                strcat(response, menu2);
                send(client_socket, response, sizeof(response), 0);
                break;
            }
        }
    }

    return 0;
}
