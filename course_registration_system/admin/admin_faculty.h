/*
================================================================================================================================
Author: Kalyani Verma
File Description: Admin functions to add, view and update faculty details
================================================================================================================================
*/

#define faculty_file "/home/kalyani/linux/course_registration_system/datafiles/faculty.txt"

struct Faculty{
    char id[10];
    char username[50];
    char password[50];
    char name[50];
    char dept[50];
    char email[50];
};


int add_faculty(int client_socket){

    //will create the database Student if not present
    int fd_faculty = open(faculty_file, O_RDWR);

    //adding student
    int option;
    struct Faculty new_faculty;
    char string_response[20];
    
    
    //set the offset to the record we want to change
    // int offset = (option - 1) * sizeof(struct data);
    lseek(fd_faculty, 0, SEEK_END);
    
    printf("Acquiring record lock on FAculty.txt\n");
    
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_END;
    lock.l_start = 0;
    lock.l_len = sizeof(struct Faculty);
    lock.l_pid = getpid();
    
    fcntl(fd_faculty, F_SETLKW, &lock);
    printf("Lock acquired on Faculty.txt\n");



    strcpy(send_response, "Enter Username for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.username, string_response);


    strcpy(send_response, "Enter password for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.password, string_response);



    strcpy(send_response, "Enter name for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.name, string_response);



    strcpy(send_response, "Enter id for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.id, string_response);



    strcpy(send_response, "Enter department for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.dept, string_response);

    
    strcpy(send_response, "Enter email for Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);
    
    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }

    strcpy(new_faculty.email, string_response);
     
    write(fd_faculty, &new_faculty, sizeof(new_faculty));    
    
    lock.l_type=F_UNLCK;
	fcntl(fd_faculty,F_SETLKW,&lock);
    
    close(fd_faculty);

    return 0;
}

int view_faculty(int client_socket){

    int fd_faculty = open(faculty_file, O_RDWR);
    char string_response[BUFFER_SIZE];
    int check;
    
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


    strcpy(send_response, "Enter the id of Faculty: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);


    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }


    while (read(fd_faculty, &faculty, sizeof(struct Faculty)) > 0) {
        // Process the faculty record
        printf("ID: %s\n", faculty.id);
        printf("Username: %s\n", faculty.username);
        printf("Name: %s\n", faculty.name);

        printf("\n");
        char client_input[10];
        strcpy(client_input, string_response);
        printf("client input: %s\n", client_input);

        if( strcmp(client_input, faculty.id) == 0){
            printf("faculty found\n");
            sprintf(send_response, "ID: %s\nUsername: %s\nName: %s\nDepartment: %s\n", faculty.id, faculty.username, faculty.name, faculty.dept );
            strcat(send_response, menu1);
            send(client_socket, send_response, strlen(send_response), 0);
            check = 1;
            break;
        }


    }

    lock.l_type=F_UNLCK;
	fcntl(fd_faculty,F_SETLKW,&lock);

    if(check == 0){
        printf("Faculty not found\n\n");
        bzero(send_response, sizeof(send_response));
        strcpy(send_response, "Faculty not found\n\n");

        strcat(send_response, menu1);
        
        send(client_socket, send_response, strlen(send_response), 0);
    }

    return 0;
}

int update_faculty(int client_socket){


    int fd_faculty = open(faculty_file, O_RDWR);
    char string_response[BUFFER_SIZE];
    int check = 0; 
    
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



    if (strchr(read_response, '\n') != NULL) {
        read_response[strlen(read_response) - 1] = '\0';
    }


    strcpy(send_response, "Enter the faculty id: ");
    send(client_socket, send_response, strlen(send_response), 0);

    bzero(read_response, sizeof(read_response));
    recv(client_socket, read_response, sizeof(read_response), 0);

    strcpy(string_response,read_response);
    printf("%s\n", string_response);

    while (read(fd_faculty, &faculty, sizeof(struct Faculty)) > 0) {

        printf("\n");
        if( strcmp(string_response, faculty.id) == 0 ){
            
            printf("Before updating\n\nID: %s\n", faculty.id);
            printf("Department: %s\n", faculty.dept);
            printf("Name: %s\n", faculty.name);
            printf("Password: %s\n", faculty.password);
            

            printf("\nEntered the main logic for update\n\n");    
            
    
    
            strcpy(send_response, "Enter what you want to update of Faculty: \n\n1. Update Name\n2. Update deaprtment\n");
            send(client_socket, send_response, strlen(send_response), 0);

            bzero(read_response, sizeof(read_response));
            recv(client_socket, read_response, sizeof(read_response), 0);

            strcpy(string_response,read_response);
            printf("%s\n", string_response);

            int client_input = atoi(string_response);
            

            switch (client_input) {
                case 1: {
                    //update name
                    strcpy(send_response, "Enter new name\n");
                    send(client_socket, send_response, strlen(send_response), 0);

                    bzero(read_response, sizeof(read_response));
                    recv(client_socket, read_response, sizeof(read_response), 0);

                    strcpy(string_response,read_response);
                    printf("%s\n", string_response);
                    
                    strcpy(faculty.name, string_response);
                    
                    break;
                }

                case 2: {
                    //update department

                    strcpy(send_response, "Enter new department\n");
                    send(client_socket, send_response, strlen(send_response), 0);

                    bzero(read_response, sizeof(read_response));
                    recv(client_socket, read_response, sizeof(read_response), 0);

                    strcpy(string_response,read_response);
                    printf("%s\n", string_response);
                    
                    strcpy(faculty.dept, string_response);
                    break;
                }
            }

            
            lseek(fd_faculty, -sizeof(struct Faculty), SEEK_CUR);
            write(fd_faculty, &faculty, sizeof(faculty)); 

            strcpy(send_response, "Faculty updated\n\n");
            strcat(send_response, menu1);

            send(client_socket, send_response, strlen(send_response), 0);
            
            printf("After updating\n\nID: %s\n", faculty.id);
            printf("Department: %s\n", faculty.dept);
            printf("Name: %s\n", faculty.name);
            printf("Password: %s\n", faculty.password);
            
            check = 1;
            break;
        }

    }

    if(check == 0){
        bzero(send_response, sizeof(send_response));
        strcat(send_response, menu1);
        send(client_socket, "Faculty not found\n\n", strlen("Faculty not found\n\n"), 0);
    }

    lock.l_type=F_UNLCK;
	fcntl(fd_faculty,F_SETLKW,&lock);

    return 0;
}
