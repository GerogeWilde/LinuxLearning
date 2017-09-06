/*************************************************************************
    > File Name: shmem.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 13 Jun 2017 08:32:45 AM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

#define PERM S_IRUSR|S_IWUSR

int main(int argc,char **argv)
{
	int shmid;
	char *p_addr,*c_addr;

	if(argc!=2)
	{
		fprintf(stderr,"Usage:%s\n\a",argv[0]);
		exit(1);
	}

	if((shmid = shmget(IPC_PRIVATE,1024,S_IRUSR|S_IWUSR))== -1)
	{
		fprintf(stderr,"Create share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}

	if(fork())
	{
		p_addr = shmat(shmid,0,0);
		memset(p_addr,'\0',1024);
		strncpy(p_addr,argv[1],1024);
		wait(NULL);
		exit(0);
	}
		else 
	{
		sleep(1);
		c_addr = shmat(shmid,0,0);
		printf("Client get %s\n",c_addr);
		exit(0);
	}

}
