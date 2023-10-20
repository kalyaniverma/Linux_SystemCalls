/*
=======================================================================================================================================
Name : 18.c
Author : Kalyani Verma
Description : Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup2.
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pipe_fd[2];

    	if (pipe(pipe_fd) == -1) {
        	perror("pipe");
        	exit(EXIT_FAILURE);
    	}

	pid_t child_pid = fork();

	if (child_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) {
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);

		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	} 
	
	else {
	     	close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);

		execlp("sh", "sh", "-c", "grep ^d | wc", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}

	return 0;
}
