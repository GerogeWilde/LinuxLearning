/*************************************************************************
    > File Name: test3.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:50:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pc,pr;

	pc = fork();

	if(0 == pc)
	{
		printf("This is the child process with pid of %d.\n",getpid());
		sleep(3);
		printf("Having passed 3 second.\n");
	}
	else if(pc > 0)
	{
		printf("I am the parent ,I want to do my job.\n");
		pr = wait(NULL);
		printf("I having catched a child process with pid of %d",pr);
	}
	exit(0);
}
