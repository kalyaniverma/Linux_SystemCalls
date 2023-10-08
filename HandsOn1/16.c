/*
=======================================================================================================================================
Name : 16.c
Author : Kalyani Verma
Description : Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>

int main() {
    struct flock lock;

    int op = open("/home/kalyani/linux/HandsOn1/16_file.txt", O_RDWR);
    if (op < 0) {
        perror("Failed");
        return (-1);
    }

    int purpose;
    printf("Enter 1 to read and 2 to write: ");
    scanf("%d", &purpose);

    switch (purpose) {
        case 1:
            lock.l_type = F_RDLCK;
            printf("Read lock implemented\n");
            break;

        case 2:
            lock.l_type = F_WRLCK;
            printf("Write lock implemented\n");
            break;

        default:
            printf("Choose correct option\n");
    }

    lock.l_whence = SEEK_SET;
    lock.l_start = 0; // Applying lock on the entire file from the starting
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entering critical section\n");

    fcntl(op, F_SETLKW, &lock);

    printf("Inside critical section\n");

    printf("Enter to unlock\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    printf("File unlocked\n");

    fcntl(op, F_SETLK, &lock);

    printf("End\n");

    return 0;
}

