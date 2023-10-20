/*
================================================================================================================================
Author: Kalyani Verma
File Description: Faculty authentication
================================================================================================================================
*/



#include "faculty.h"

#define faculty_Path "/home/kalyani/linux/project/faculty.txt"


/*struct faculty{
    char id;
    char username[50];
    char password[50];
    char name[50];
    int dept[50];
    char email[50];
    // char course_enrolled[4][30];
};*/


int faculty_login(int client_socket){

    char buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];

    char faculty_username1[20] ;
    char faculty_password1[20] ;
    char menu[300];
    int credentials = 1;

    while(1){
        //faculty sign in for username
        if(credentials == 1){
            strcpy(menu, "\nYou selected faculty\nSign in for faculty:\nUsername: ");
            send(client_socket, menu, strlen(menu), 0);
        }
        else{
            strcpy(menu, "\n\nYour have entered wrong credentials\n\n Sign in for faculty...\nUsername: ");
            send(client_socket, menu, strlen(menu), 0);
        }

        bzero(buffer, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        strcpy(faculty_username1,buffer);
        printf("%s\n", faculty_username1);
        
        if (strchr(buffer, '\n') != NULL) {
            buffer[strlen(buffer) - 1] = '\0';
        }

        //faculty sign in for password
        bzero(menu, sizeof(menu));
        strcpy(menu, "Password: ");
        send(client_socket, menu, strlen(menu), 0);

        bzero(buffer, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        if (strchr(buffer, '\n') != NULL) {
            buffer[strlen(buffer) - 1] = '\0';
        }

        strcpy(faculty_password1, buffer);
        printf("%s\n", faculty_password1);


        int fd_faculty = open(faculty_Path,O_RDONLY);;
        char string_response[BUFFER_SIZE];
        
        struct flock lock;
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = sizeof(struct Faculty);
        lock.l_pid = getpid();

        if (fcntl(fd_faculty, F_SETLKW, &lock) == -1) {
            perror("Error acquiring file lock");
            close(fd_faculty);
            return 0;
        }
        struct Faculty faculty;



        while (read(fd_faculty, &faculty, sizeof(struct Faculty)) > 0) {

            if (strcmp(faculty_username1, faculty.username) == 0 && strcmp(faculty_password1, faculty.password) == 0) {
                
                // Process the faculty record
                printf("ID: %s\n", faculty.id);
                printf("Username: %s\n", faculty.username);
                printf("Name: %s\n", faculty.name);

                printf("\n");
                char faculty_id[10];
                strcpy(faculty_id, faculty.id);
                credentials = 1;
                faculty_menu(faculty_id, client_socket);
                break;
            }
            else{
                credentials = 0;
                break;
            }

        }

        lock.l_type=F_UNLCK;
        fcntl(fd_faculty,F_SETLKW,&lock);
        if(credentials == 1){
            break;
        }
    }


    close(client_socket);
    return 0;
}
