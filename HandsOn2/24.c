/*
=======================================================================================================================================
Name : 24.c
Author : Kalyani Verma
Description : Write a program to create a message queue and print the key and message queue id
Date: 10th Oct, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <sys/msg.h>

int main() {
	// 'a' = ASCII value of "a" given as proj_id and "." will be string used to create key
	int key = ftok(".", 'a');
	int msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744);
	printf("key=0x%0x\t msgid=%d\n", key, msgid); // %0x for Hexadecimal value
}

