/*************************************************************************
    > File Name: fork1.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 23 May 2017 08:24:33 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>


int counter = 1;
int main()
{
	pid_t pid;
	pid = fork();
	

	if(pid < 0)
	{
		printf("Error.\n");
//		printf("counter = %d",counter);
	}

	if(pid == 0)
	{
		printf("I am the child process.my ID is %d.\n",getpid());
//		printf("counter = %d",counter);
	}
	else 
	{
		printf("I am the parent process.my ID is %d.\n",getpid());
//		printf("counter = %d",counter);
	}

	return 0;
}
