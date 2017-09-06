/*************************************************************************
    > File Name: test1.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:37:58 AM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>



int main()
{
	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		printf("Error.\n");
	}
	if(pid == 0)
	{
		printf("I am child,myID is %d.\n",getpid());
	}
	if(pid >0)
	{
		printf("I an parent,myID is %d.\n",getpid());
	}
	return 0;
}
