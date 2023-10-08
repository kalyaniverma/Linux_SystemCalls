/*
=======================================================================================================================================
Name : 21.c
Author : Kalyani Verma
Description : Write a program, call fork and print the parent and child process id.
Date: 1st Sept,2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
	int ppid = getpid();
	printf("Parent Process ID: %d\n", ppid);

	int cpid = fork();

	if(cpid)
		printf("Child Process ID: %d\n", cpid);

	return 0;

}
