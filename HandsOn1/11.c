/*
=======================================================================================================================================
Name : 11.c
Author : Kalyani Verma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and
	      check whether the file is updated properly or not.
		a. use dup
		b. use dup2
		c. use fcntl
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv) {
	int op = open("11_file.txt", O_RDWR);
	if(op < 0) perror("Failed");
	char op_str[] = "Using original fd\n";
	write(op, op_str, strlen(op_str)+1);

	int dp = dup(op);
	char dp_str[] = "Using dup()\n";
	write(dp, dp_str, strlen(dp_str)+1);
	write(op, op_str, strlen(op_str)+1);


	int dp2 = dup2(op, dp);
	char dp2_str[] = "Using dup2()\n";
	write(dp, dp2_str, strlen(dp_str)+1);
	write(op, op_str, strlen(op_str)+1);

	int fcnt = fcntl(op, F_DUPFD, 0);
	char fcnt_str[] = "Using fcntl()\n";
	write(fcnt, fcnt_str, strlen(fcnt_str)+1);
	write(op, op_str, strlen(op_str)+1);

	return 0;
}
