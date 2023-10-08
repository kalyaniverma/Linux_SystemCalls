/*
=======================================================================================================================================
Name : 13.c
Author : Kalyani Verma
Description : Write a program to wait for a STDIN for 10 seconds using select.
	      Write a proper print statement to verify whether the data is available within 10 seconds or not.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include<stdlib.h>
#include <sys/select.h>

int main() {
	fd_set dsrf;
	struct timeval alpha;

	FD_ZERO(&dsrf);
	FD_SET(0, &dsrf);

	printf("Waiting for input...\n");

	alpha.tv_sec = 10;
	int ret = select(1, &dsrf, NULL, NULL, &alpha);

	if(ret) 
		printf("Input given");
	else
		printf("No input given\n");

	getchar();
	return 0;
}
