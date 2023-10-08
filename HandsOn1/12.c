/*
=======================================================================================================================================
Name : 12.c
Author : Kalyani Verma
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <fcntl.h>
#include <stdio.h>

int main() {
	int op = open("/home/kalyani/linux/HandsOn1/12_file.txt", O_RDWR);

	int fc = fcntl(op, F_GETFL);
	if(fc < 0) perror("Failed");

	switch(fc){
		case 32768 : printf("File opening mode: r\n"); break;
		case 32769 : printf("File opening mode: w\n"); break;
		case 33793 : printf("File opening mode: a\n"); break;
		case 32770 : printf("File opening mode: r+ || w+\n"); break;
		case 32794 : printf("File opening mode: a+\n"); break;
	}

	return 0;

}
