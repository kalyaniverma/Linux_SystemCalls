/*
=======================================================================================================================================
Name : 20_read.c
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
	fd = open("myfifo", O_RDONLY);
	read(fd, buff, sizeof(buff));
	printf("The text from FIFO file: %s\n", buff);
}
