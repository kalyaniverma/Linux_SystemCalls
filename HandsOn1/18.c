/*
=======================================================================================================================================
Name : 18.c
Author : Kalyani Verma
Description : Write a program to perform Record locking.
	      a. Implement write lock
	      b. Implement read lock
	      Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define FNAME "/home/kalyani/linux/HandsOn1/18_record.txt"
struct data {
	int val;
};

int main() {
	int fd = open(FNAME, O_RDWR);

	/*struct data r1, r2, r3;
        r1.val = 1;
        r2.val = 2;
        r3.val = 3;
        write(fd, &r1, sizeof(r1));
        write(fd, &r2, sizeof(r2));
        write(fd, &r3, sizeof(r3));
        //close(fd);*/

	while(1) {
		int option;
		printf("Enter record (1-3) to lock, or -1 to quit: ");
		scanf("%d", &option);
		if(option < 0)
			break;
		
		int offset = (option - 1) * sizeof(struct data);
		lseek(fd, offset, SEEK_SET);

		printf("Acquiring record lock\n");
		
		struct flock lock;
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = offset;
		lock.l_len = sizeof(struct data);
		lock.l_pid = getpid();
		
		fcntl(fd, F_SETLK, &lock);
		printf("Lock acquired\n");
		
		struct data currRecord;
		//reading the record to currRecord
		read(fd, &currRecord, sizeof(currRecord));
		printf("Previous value of record: %d\n", currRecord.val);
		//updating the value of the currRecord
		currRecord.val++;
		printf("Current value of record: %d\n", currRecord.val);

		//taking the pointer to the record we want to change
		lseek(fd, -sizeof(struct data), SEEK_CUR);
		
		//wrinting the updated value
		write(fd, &currRecord, sizeof(currRecord));
		printf("Releasing record lock\n");
		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("Lock released\n");
	}
	return 0;
}
		
