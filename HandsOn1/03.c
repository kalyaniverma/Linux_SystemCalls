/*
=======================================================================================================================================
Name : 03.c
Author : Kalyani Verma
Description : Write a program to create a file and print the file descriptor value. Use creat() system call.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	int status = creat("03_file.txt", O_RDWR);
	if(status < 0) perror("Failed");
	else printf("File Decriptor Value is: %d\n", status);
	return 0;
}
