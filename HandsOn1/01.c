/*
=======================================================================================================================================
Name : 01.c
Author : Kalyani Verma
Description : Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call)
		b. hard link (link system call)
		c. FIFO (mkfifo Library Function or mknod system call)
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int v = symlink("/home/kalyani/linux/HandsOn1/01_file.txt", "/home/kalyani/linux/HandsOn1/01/01_SoftFile");
	if(v<0){
		perror("Failed");
		return 1;
	}

	else
		printf("Soft Link Created\n");

	int f = link("/home/kalyani/linux/HandsOn1/01/01_file.txt" , "/home/kalyani/linux/HandsOn1/01/01_HardFile");
	if(f<0){
		perror("Failed");
		return 1;
	}
	else
		printf("Hard Link Created\n");

	int e = mknod("/home/kalyani/linux/HandsOn1/01/01_fifo", S_IFIFO|0666,0);
       	if(e<0){
		perror("Failed");
		return 1;
	}
	else
		printf("FIFO file created\n");

	return 0;
}
