/*
=======================================================================================================================================
Name : 21_user2.c
Author : Kalyani Verma
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 10th Oct, 2023.
=======================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd1, fd2;
        char buff1[80], buff2[80];

        fd1 = open("21_fifo1", O_RDONLY);
        fd2 = open("21_fifo2", O_WRONLY);
	read(fd1, buff1, sizeof(buff1));
	printf("The message from user 1: %s\n", buff1);
        printf("Enter the message: ");
        scanf(" %[^\n]", buff2);
        write(fd2, buff2, sizeof(buff2));
}
