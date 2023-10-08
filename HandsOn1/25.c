/*
======================================================================================================================================
Name : 25.c
Author : Kalyani Verma
Description : Write a program to create three child processes. The parent should wait for a particular child.
Date: 9th Sept,2023.
======================================================================================================================================
*/


#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void Child_process(int child_no, int child_wait) {

	int pid = getppid();

	printf("==================================================================\n");
	printf("Child process %d created with pid: %d\n", child_no, getpid());

	//if this child is to be waited for then we will make it run for longer time for the parent to wait
	if(child_wait == child_no) {

		sleep(5); //to check by parent pid to see if parent still exists after this sleep
		if(pid != 1) printf("Inside Child %d, Parent PID is %d, means parent still exists\n",child_no, pid);
		sleep(10); //to make the child processing for longer period of time
		printf("Child process %d stopped\n", child_no);
	}

	else printf("Child process %d stopped\n", child_no);

}

int main() {

	int ch, forks[4], status;
	printf("For which child you want parent to wait (1/2/3): ");
	scanf("%d", &ch);

	for (int i = 1; i <= 3; i++) {
        forks[i] = fork();

        if (forks[i] == 0) {
            Child_process(i, ch);
            exit(0); // Child process should exit after its work
        }
    }

    //if (getpid() != forks[ch]) {
        
	printf("PARENT PROCESS STARTED WITH PID: %d\n", getpid());
	sleep(5);
        printf("==================================================================\n");
        printf("PARENT PROCESS WAITING\n");
        waitpid(forks[ch], &status, 0); // Wait for the specific child process
        printf("PARENT PROCESS STOPPED\n");
        printf("==================================================================\n");
   // }

    return 0;
}
