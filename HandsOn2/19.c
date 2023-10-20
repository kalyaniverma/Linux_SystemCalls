/*
=======================================================================================================================================
Name : 19.c
Author : Kalyani Verma
Description : Create a FIFO file by
		a. mknod command
		b. mkfifo command
		c. use strace command to find out, which command (mknod or mkfifo) is better.
		d. mknod system call
		e. mkfifo library function
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

	//using mknod system call
	const char *fifo1 = "19_fifo1";

	//third parameter is dev which tells the number of device numbers. for FIFO it is set to 0
	int error1 = mknod(fifo1, S_IFIFO | 0666, 0);

	if(error1 == 0) {
		printf("%s file created using mknod system call\n", fifo1);
	}

	else {
		perror("Failed");
		return 1;
	}
	
	
	// Using mkfifo function call
	const char *fifo2 = "19_fifo2";

	int error2 = mkfifo(fifo2, 0666);

	if(error2 == 0) {
		printf("%s file created using mkfifo function call\n", fifo2);
	}

	else {
		perror("Failed");
		return 1;
	}

	return 0;
}
