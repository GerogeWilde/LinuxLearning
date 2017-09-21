/*************************************************************************
    > File Name: pipe2_mkfifo.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 30 May 2017 09:29:37 AM CST
 ************************************************************************/

#include<stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define FIFO "/tmp/myfifo"


main(int argc,char** argv)
{
	char	buf_r[100];
	int		fd;
	int		nread;

	//Create FIFO

	if((mkfifo(FIFO,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
	//Create named pipes (FIFOs) with the given NAMEs.

		printf("cannot create fifoserver!\n");

	printf("preparing for reading bytes...\n");

	memset(buf_r,0,sizeof(buf_r));


	//Open FIFO
	fd = open(FIFO,O_RDONLY|O_NONBLOCK,0);
	if(-1 == fd)
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		memset(buf_r,0,sizeof(buf_r));

		if((nread = read(fd,buf_r,100)) == -1)
		{
			if(errno == EAGAIN)
				printf("no data yet\n");
		}
		printf("read %s from FIFO\n",buf_r);
		sleep(1);
	}
	pause();
	unlink(FIFO);

}
