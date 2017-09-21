/*************************************************************************
    > File Name: test1.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 09:01:13 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int pipe_fd[2];
	pid_t pid;
	char buf_r[100];
	char *p_wbuf;
	int r_num;

	memset(buf_r,0,sizeof(buf_r));

	if(pipe(pipe_fd)<0)
	{
		printf("pipe create error\n");
		return -1;
	}
	if((pid=fork())==0)
	{
		printf("\n");
		close(pipe_fd[1]);
		sleep(2);
		if((r_num = read(pipe_fd[0],buf_r,100))>0)
		{
			printf("%d numbers read from the pipe is %s\n",r_num,buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	}
	if((pid=fork())>0)
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"hello",5)!=-1)
			printf("parent write1 hello!\n");
		if(write(pipe_fd[1],"hello",5)!=-1)
			printf("parent write2 pipe!\n");

		close(pipe_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0);
		exit(0);
	}
}
