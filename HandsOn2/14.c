/*
=======================================================================================================================================
Name : 14.c
Author : Kalyani Verma
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 08th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

	int pipefd[2];
	char buf;
	int count_buf, eof = 0;

	if(!pipe(pipefd)) 
	{
		while(1)
		{
			scanf("%c", &buf);
			count_buf = write(pipefd[1], &buf, 1);
			if(count_buf == 0) {
				eof = 1;
				break;
			}
			else {
				count_buf = read(pipefd[0], &buf, 1);
				if(buf == '\n') break;
			}
			printf("%c", buf);
		}
		printf("\n");
	}

	else
		perror("Failed");

	return 0;
}
