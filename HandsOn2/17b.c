/*
=======================================================================================================================================
Name : 17b.c
Author : Kalyani Verma
Description : Write a program to execute ls -l | wc.
		a. use dup
		b. use dup2
		c. use fcntl
Date: 09th Oct, 2023.
=======================================================================================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){

	int fd[2];
	pipe(fd);
	if(!fork()){
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls","ls","-l",NULL);
	}
	else{
		close(fd[1]);
		dup2(fd[0],0);
		execlp("wc","wc",NULL);
	}
	wait(0);
	
	return 0;
}
