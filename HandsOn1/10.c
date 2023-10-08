/*
=======================================================================================================================================
Name : 10.c
Author : Kalyani Verma
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and
	      write again 10 bytes. 
		a. check the return value of lseek.
		b. open the file with od and check the empty spaces in between the data.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int op = open("/home/kalyani/linux/HandsOn1/10_file.txt", O_RDWR);
	if(op < 0) perror("Failed");

	else {
		char buf[] = "Program number 10\n";
		
		int wr = write(op, buf, sizeof(buf));
		
		int ls = lseek(op, 10, SEEK_CUR);
		if(ls < 0) perror("Failed");
		
		else {
			printf("Return Value of lseek: %d\n", ls);
			int wr1 = write(op, buf, sizeof(buf));
		}
	}
	return 0;
}
