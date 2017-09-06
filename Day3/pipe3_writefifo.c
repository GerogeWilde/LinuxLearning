/*************************************************************************
    > File Name: pipe3_writefifo.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 30 May 2017 10:06:13 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define FIFO_SERVER "/tmp/myfifo"

main(int argc,char** argv)
{
	int fd;
	char w_buf[100];
	int nwrite;

	//Open FIFO
	

	fd = open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0);

	if( argc == 1){
		printf("Please send something\n");
		exit(-1);
	}
	
	strcpy(w_buf,argv[1]);

	/*write something in FIFO */
	if((nwrite = write(fd,w_buf,100)) == -1){

		if(errno == EAGAIN) printf("The FIFO has not been read yet. Please try later\n");

	}
	else
		printf("Write %s to the FIFO\n",w_buf);
}

		
