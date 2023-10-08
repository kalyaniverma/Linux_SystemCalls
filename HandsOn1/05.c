/*
=======================================================================================================================================
Name : 05.c
Author : Kalyani Verma
Description : Write a program to create five new files with infinite loop.
	      Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


//#RUN WITH "./05_output &" and run cmd "cd /proc/<pid>/fd"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int st = creat("/home/kalyani/linux/HandsOn1/05/05_file1.txt", O_RDWR);
	if(st<0){
		perror("Failed");
	}

	else {
		printf("05_file1.txt created\n");
		creat("/home/kalyani/linux/HandsOn1/05/05_file2.txt", O_RDWR);
		printf("05_file2.txt created\n");
		creat("/home/kalyani/linux/HandsOn1/05/05_file3.txt", O_RDWR);
		printf("05_file3.txt created\n");
		creat("/home/kalyani/linux/HandsOn1/05/05_file4.txt", O_RDWR);
		printf("05_file4.txt created\n");
		creat("/home/kalyani/linux/HandsOn1/05/05_file5.txt", O_RDWR);
		printf("05_file5.txt created\n");
	}
	while(1);
	return 0;
}
