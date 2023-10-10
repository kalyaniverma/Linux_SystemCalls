/*
=======================================================================================================================================
Name : 29.c
Author : Kalyani Verma
Description : Write a program to remove the message queue.
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	int msqid;
	key_t key;
	
	// Generate a key for the message queue (use the same key you used to create the queue)
	key = ftok("/tmp", 'A'); // Replace with the appropriate key and path
	if (key == -1) {
		perror("ftok");
		exit(1);
	}
	
	// Get the message queue ID
	msqid = msgget(key, 0);
	if (msqid == -1) {
		perror("msgget");
		exit(1);
	}
	
	// Remove the message queue
	if (msgctl(msqid, IPC_RMID, NULL) == -1) {
		perror("msgctl (IPC_RMID)");
		exit(1);
	}
	
	printf("Message queue with ID: %d removed successfully.\n", msqid);
	return 0;
}

