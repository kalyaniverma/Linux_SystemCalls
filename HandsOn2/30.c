/*
=======================================================================================================================================
Name : 30.c
Author : Kalyani Verma
Description : Write a program to create a shared memory.
	a. write some data to the shared memory
	b. attach with O_RDONLY and check whether you are able to overwrite.
	c. detach the shared memory
	d. remove the shared memory
Date: 11th Oct, 2023.
=======================================================================================================================================
*/


#include <sys/types.h> // Import for `ftok`, `shmget`, `shmat`
#include <sys/ipc.h>   // Import for `ftok`, `shmget`
#include <sys/shm.h>   // Import for `shmget`, `shmat`
#include <unistd.h>    // Import for `_exit`
#include <stdio.h>     // Import for `perror` & `printf`

int main()
{
	int k, shmid;
    	char  *data;

	// (a) Writing data to shared memory
    	k = ftok(".",'a');
    	shmid = shmget(k,1024,IPC_CREAT | 0744);
    	data = shmat(shmid,0,0);
    	printf("Enter data: ");
    	scanf(" %[^\n]",data);
    	printf("Entered data: %s\n", data);
    
    	    	
    	// (b) Checking if able to overwrite or not
    	data = shmat(shmid,0,SHM_RDONLY);   //will give error because we changed the permission to read-only, so cannot overwrite
    	printf("Enter data to overwrite: ");
    	scanf(" %[^\n]",data);
    	
    	printf("Overwritten data: %s\n", data);
    	
    	
    	// (c) Detaching the shared memory
    	if(shmdt(data)==-1)
        	perror("Failed");
        	
        printf("Shared memory detached\n");
        
        
        // (d) Removing the shared memory
        if(shmctl(shmid, IPC_RMID, NULL) == -1)
        	perror("Failed");
        	
    	printf("Shared memory removed\n");
    	
    	return 0;
    
    
}


