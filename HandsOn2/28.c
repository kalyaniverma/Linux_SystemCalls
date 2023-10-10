/*
=======================================================================================================================================
Name : 28.c
Author : Kalyani Verma
Description : Write a program to change the exiting message queue permission (use msqid_ds structure)
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

int main() {
	int msqid;
	key_t key;
	struct msqid_ds queue_info;
	
	// Generate a key for the message queue
	key = ftok("/tmp", 'A');
	if (key == -1) {
		perror("ftok");
		exit(1);
	}
	
	// Get the message queue ID
	msqid = msgget(key,0);
	if (msqid == -1) {
		perror("msgget");
		exit(1);
	}
	
	// Get the current message queue attributes
	if (msgctl(msqid, IPC_STAT, &queue_info) == -1) {
		perror("msgctl (IPC_STAT)");
		exit(1);
	}

	printf("Current message queue permission: %#o\n", queue_info.msg_perm.mode);
	
	// Modify the permission to 0444 (rw-r--r--)
	queue_info.msg_perm.mode = 0444;
	
	// Set the modified attributes back to the message queue
	if (msgctl(msqid, IPC_SET, &queue_info) == -1) {
		perror("msgctl (IPC_SET)");
		exit(1);
	}
	
	printf("Modified message queue permission: %#o\n", queue_info.msg_perm.mode);
	return 0;
}
