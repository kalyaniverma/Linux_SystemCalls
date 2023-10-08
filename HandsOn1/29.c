/*
=======================================================================================================================================
Name : 29.c
Author : Kalyani Verma
Description : Write a program to get scheduling policy and modify the scheduling policy.
Date: 8th Sept,2023.
=======================================================================================================================================
*/


//WE WILL HAVE TO RUN THE PROGRAM WITH SUDO COMMAND.
#include <stdio.h>
#include <sched.h>
#include <unistd.h>

void sch_policy(int policy) {

	switch(policy) {
		case 0:
			printf("Normal Scheduling\n");
			break;

		case 1:
			printf("First-In-First-Out Scheduling\n");
			break;

		case 2:
			printf("Round-Robin Scheduling\n");
			break;

		case 3:
			printf("Batch Scheduling\n");
			break;

		case 5:
			printf("Idle Scheduling\n");
			break;

		case 6:
			printf("Deadline Scheduling\n");
			break;

		default:
			printf("Invalid choice\n");

	}
}

int main() {

	//GETTING CURRENT POLICY
	int get_sch = sched_getscheduler(getpid());
	printf("Current policy: ");
	sch_policy(get_sch);

	//MODIFYING CURRENT POLICY
	int set_sch;
	struct sched_param param;
	printf("Choose new Scheduling Policy: FIFO(1) or Round-Robin(2)\n");
	scanf("%d", &set_sch);
	param.sched_priority = 99;
	
	sched_setscheduler(getpid(), set_sch, &param);
	get_sch = sched_getscheduler(getpid());
	printf("Modified policy: ");
        sch_policy(get_sch);

	return 0;

}
