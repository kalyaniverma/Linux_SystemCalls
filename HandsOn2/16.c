/*
=======================================================================================================================================
Name : 16.c
Author : Kalyani Verma
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 09th Oct, 2023.
=======================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	char buf_pc[80], buf_cp[80];
	int fd_pc[2], fd_cp[2];
	
	pipe(fd_pc);
	pipe(fd_cp);
	if(fork()) {
		close(fd_pc[0]); //Close read-end of pipe for parent
		close(fd_cp[1]); //Close write-end of pipe for parent
		printf("Message from Parent to Child: ");
		scanf(" %[^\n]", buf_pc); // Read till newline encountered
		write(fd_pc[1], buf_pc, sizeof(buf_pc)); //write from parent to child
		read(fd_cp[0], buf_cp, sizeof(buf_cp)); //read from child to parent
		printf("Message from Child: %s\n", buf_cp);
	}
	else {
		close(fd_pc[1]); // Close write-end of pipe for child
		close(fd_cp[0]); //Close read-end of pipe for child
		read(fd_pc[0], buf_pc, sizeof(buf_pc)); //read from parent to child
		printf("Message from Parent: %s\n", buf_pc);
		
		printf("Message from Child to Parent: ");
		scanf(" %[^\n]", buf_cp);
		write(fd_cp[1], buf_cp, sizeof(buf_cp)); //write from child to parent
	}
}


