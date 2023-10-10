/*
=======================================================================================================================================
Name : 26.c
Author : Kalyani Verma
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

int main() {
	struct msg {
		long int m_type;
		char message[80];
	} myq;
	int key = ftok(".", 'a');
	int mqid = msgget(key, 0);
	printf("Enter message type: ");
	scanf("%ld", &myq.m_type);
	printf("Enter message text: ");
	scanf(" %[^\n]", myq.message);
	int size = strlen(myq.message);
	// size + 1 to accommodate terminating character
	msgsnd(mqid, &myq, size + 1, 0);
}

