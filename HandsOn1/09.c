/*
=======================================================================================================================================
Name : 09.c
Author : Kalyani Verma
Description : Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
Date: 29th Aug, 2023.
=======================================================================================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>
#include <time.h>

int main() {

	struct stat buffer;
	int st;

	stat("/home/kalyani/linux/HandsOn1/09_file.txt", &buffer);

	printf("(a) File inode number: %lu\n", buffer.st_ino);
	printf("(b) Number of Hard Links: %ld\n", buffer.st_nlink);
	printf("(c) User ID of owner: %d\n", buffer.st_uid);
	printf("(d) Group ID of owner: %d\n", buffer.st_gid);
	printf("(e) Total size in Bytes: %ld\n", buffer.st_size);
	printf("(f) Block Size: %ld\n", buffer.st_blksize);
	printf("(g) Number of blocks: %jd\n", buffer.st_blocks);
	printf("(h) Time of last access: %s", ctime(&buffer.st_atime));
        printf("(i) Time of last modification: %s", ctime(&buffer.st_mtime));
	printf("(j) Time of last change: %s", ctime(&buffer.st_ctime));	

	return 0;

}
	
