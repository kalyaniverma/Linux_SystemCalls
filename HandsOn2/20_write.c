/*
=======================================================================================================================================
Name : 20_write.c
Author : Kalyani Verma
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 09th Oct, 2023.
=======================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	char buff[80];
	fd = open("20_fifo",O_WRONLY);
	printf("Enter the text:");
	scanf(" %[^\n]", buff);
	write(fd, buff, sizeof(buff));
}
