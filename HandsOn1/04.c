/*
=======================================================================================================================================
Name : 04.c
Author : Kalyani Verma
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	int status = open("04_file.txt", O_EXCL ,O_RDWR);
	if(status < 0)
		perror("Failed");
	else
		printf("File opened\n");

	return 0;

}
