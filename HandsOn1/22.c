/*
=======================================================================================================================================
Name : 22.c
Author : Kalyani Verma
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes.
	      Check output of the file.
Date: 1st Sept,2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	if(argc != 2) {
                printf("Enter file name to be opened\n");
	}

	else {
		int op = open(argv[1], O_RDWR);
		int cpid = fork();
		
		if(cpid == 0) {
			write(op, "Hello Child Process\n", 20);
		}
		
		else {
			write(op, "Hello Parent Process\n", 22);
			int cl = close(op);
			if(cl<0) perror("Failed: ");
		}
		return 0;
	}
}
