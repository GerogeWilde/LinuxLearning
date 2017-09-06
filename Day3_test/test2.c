/*************************************************************************
    > File Name: test2.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 09:21:52 AM CST
 ************************************************************************/

#include<stdio.h>

#define FIFO "/tmp/myfifo"

int main(int argc,char **argv[])
{
	char buf_r[100];
	int	 fd;
	int  nread;

	if((mkdir(FIFO,O_CREAT|O_EXCL)<0) && (errno!=EEXIST))
		printf("Cannot create fifoserver!\n");

	printf("Perparing for reading bytes...\n");

	memset(buf_r,0,sizeof(buf_r));

	fd = open(FIFO,O_RENOLY|O_NONBLOCK,0);
	if(-1 == fd)
	{
		preero()
	}
}
