/*
=======================================================================================================================================
Name : 22_write.c
Author : Kalyani Verma
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 10th Oct, 2023.
=======================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	char buff[80];
	fd = open("22_fifo",O_WRONLY);
	printf("Enter the text:");
	scanf(" %[^\n]", buff);
	write(fd, buff, sizeof(buff));
}
