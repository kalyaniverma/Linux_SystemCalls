/*
=======================================================================================================================================
Name : 23.c
Author : Kalyani Verma
Description : Write a program to create a Zombie state of the running program.
Date: 1st Sept,2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Parent Process Started\n");

	int cpid = fork();

	if(!cpid) {
		printf("Child Process Started\n");
		printf("In child section pid is: %d\n", cpid);
		printf("Child Process Stopped\n");

	}
	else {
		printf("In parent section, child pid is: %d\n",cpid);
		sleep(50);
		printf("Parent Process Stopped\n");
	}
	return 0;

}
