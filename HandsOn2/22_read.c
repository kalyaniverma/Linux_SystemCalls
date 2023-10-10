/*
=======================================================================================================================================
Name : 22_read.c
Author : Kalyani Verma
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 10th Oct, 2023.
=======================================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
	
	int fd;
	char buff[80];
	fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 10;

	fd = open("22_fifo", O_RDONLY);
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	if (!select(fd + 1, &rfds, NULL, NULL, &tv))
		printf("No data is available for reading yet\n");
	else {
		printf("Data is available now\n");
		read(fd, buff, sizeof(buff));
		printf("Data from FIFO: %s\n", buff);
	}
}
