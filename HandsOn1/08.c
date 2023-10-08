/*
=======================================================================================================================================
Name : 08.c
Author : Kalyani Verma
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. 
	      Close the file when end of file is reached.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]){
	int op = open(argv[1], O_RDONLY);
	if(op == -1){
		perror("Failed");
		return -1;
	}
	int eof = 0;
	while(!eof){
		char buf;
		while(1){
			int r=read(op, &buf,1);
			if(r == 0){
				eof = 1;
				break;
			}
			else{
				printf("%c", buf);
				if(buf == '\n')
					break;
			}
		}
	}

	int op_close = close(op);
	if(op_close==-1)
		perror("Failed");
	
	return 0;
}
