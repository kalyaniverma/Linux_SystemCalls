/*
=======================================================================================================================================
Name : 17_createTicket.c
Author : Kalyani Verma
Description : Write a program to simulate online ticket reservation. Implement write lock.
              Write a program to open a file, store a ticket number and exit.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>
int main(){

	struct{
		int ticket;
	}data;
	data.ticket=1;
	
	int fd = open("17_ticket.txt", O_RDWR);
	if(fd < 0)
		perror("Failed");

	write(fd, &data, sizeof(data));
	close(fd);

	return 0;
}
