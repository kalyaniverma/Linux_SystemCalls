/*
================================================================================================================================
Author: Kalyani Verma
File Description: Display student menu
================================================================================================================================
*/



#include "student_manage.h"

int student_menu(struct Student loggedin_student, int client_socket){
    char student_menu[] = "\n\n=============== Welcome to Student Menu ===============\nEnter the Option:\n1. View all courses\n2. Enroll new course\n3. Drop course\n4. View Enrolled details\n5. Change password\n6. Logout\n";
    
    send(client_socket, student_menu, sizeof(student_menu), 0);

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

                view_all_courses(loggedin_student, client_socket);
                
                break;
            }
            case 2: {

                enroll_course(loggedin_student, client_socket);
                //send handled
                break;
            }
            case 3: {

                drop_course(loggedin_student, client_socket);
                //send handled

                break;
            }
            case 4: {
                enrolled_course(loggedin_student, client_socket);
                //send handled
                break;
            }
            case 5: {
                change_password(loggedin_student, client_socket);
                char response[] = "Updated Student Details.\n";
                strcat(response, menu);
                send(client_socket, response, sizeof(response), 0);
                //send handled
                break;
            }
            
            case 6: {
                // Logout functionality
                // char response[] = "Logged out.\n";
                // send(client_socket, response, sizeof(response), 0);
                return 0;
                break;
            }
            default: {
                char response[] = "Invalid choice. Please select a valid option.\n";
                send(client_socket, response, sizeof(response), 0);
                break;
            }
        }
    }

    return 0;
}
