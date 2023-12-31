/*
=======================================================================================================================================
Name : 17.c
Author : Kalyani Verma
Description : Write a program to simulate online ticket reservation. Implement write lock. 
	      Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print 	             the new ticket number then close the file.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>
#define FNAME "/home/kalyani/linux/HandsOn1/17_ticket.txt"

struct data{
	int ticket;
};
int main(){
	
        int fd = open(FNAME, O_RDWR);
        if(fd < 0)
                perror("Failed");

	struct flock lock;
	
   	lock.l_type = F_WRLCK;
   	lock.l_whence = SEEK_SET;
   	lock.l_start = 0;
   	lock.l_len = 0;
	lock.l_pid = getpid();

	fcntl(fd ,F_SETLKW, &lock);
        struct data ticket_info;
        read(fd, &ticket_info, sizeof(ticket_info));

	printf("Value of ticket before: %d\n",ticket_info.ticket);
        ticket_info.ticket++;
	
	lseek(fd, 0L, SEEK_SET);	

	printf("Value of ticket after: %d\n",ticket_info.ticket);
	write(fd, &ticket_info, sizeof(ticket_info));
	
	printf("Press enter to unlock\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	
	printf("End\n");
   	
        close(fd);

        return 0;
}
