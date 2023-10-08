/*
=======================================================================================================================================
Name : 24.c
Author : Kalyani Verma
Description : Write a program to create an orphan process.
Date: 1st Sept,2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
        printf("Parent Process Started\n");

        int cpid = fork();

        if(!cpid) {
		
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nChild Process Started\n");
                printf("In child section, child pid is: %d\n", getpid());
		printf("In child section, before becoming orphan parent pid is: %d\n", getppid());
		sleep(2);
		printf("In child section, after becoming orphan parent pid is: %d\n", getppid()); //Parent stopped before child and will return 1 as its pid, means child is orphan now.
		sleep(30);
                printf("Child Process Stopped\n");
        }
        else {
                printf("In parent section pid is: %d\n",getpid());
		sleep(1);
                printf("Parent Process Stopped\n");

        }
        return 0;

}
