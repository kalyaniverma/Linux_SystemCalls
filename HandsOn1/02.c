/*
=======================================================================================================================================
Name : 02.c
Author : Kalyani Verma
Description : Write a simple program to execute in an infinite loop at the background.
	      Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


//#RUN WITH "./02_output &"

#include<stdio.h>

int main(){
	while(1); //check the status of process using "cat /proc/<pid>/status"
	return 0;
}

