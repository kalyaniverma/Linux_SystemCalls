/*
=======================================================================================================================================
Name : 06.c
Author : Kalyani Verma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <unistd.h>
#include <stdio.h>

int main() {
	char buf[100];
	int rd = read(0, buf, sizeof(buf));
	if(rd<0) perror("Failed");
	printf("Input Bytes: %d\n", rd);

	printf("\n");
	int wr = write(0, buf, sizeof(buf));
	if(wr<0) perror("Failed");
	printf("Output Bytes: %d\n", rd);
	return 0;
}
