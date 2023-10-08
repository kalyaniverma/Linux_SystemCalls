/*
=======================================================================================================================================
Name : 20.c
Author : Kalyani Verma
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sept,2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
	int mod;
	int pr = getpriority(PRIO_PROCESS, 0);

	printf("Priority of current process is: %d\n", pr);
	
	printf("New process priority Increment[-19 to +20): ");
	scanf("%d", &mod);

	pr = nice(mod);
	printf("Modified Priority is: %d\n", pr);

	return 0;
}
