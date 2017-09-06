/*************************************************************************
    > File Name: alarm.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 06 Jun 2017 09:18:30 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int count = 0;


void my_func(int sign_no)
{
	if(sign_no == SIGINT)
	{
		printf("I have got SIGINT\n");
	}
	else if(sign_no == SIGQUIT)
	{
		printf("I have got SIGQUIT\n");
	}
	else if(sign_no == SIGALRM)
	{
		printf("count == %d\n",count++);
		alarm(2);
	}
}



int main()
{
	printf("Waiting for signal SIGIT or SIGQUIT \n");

	signal(SIGINT,my_func);
	signal(SIGQUIT,my_func);
	signal(SIGKILL,my_func);
	signal(SIGALRM,my_func);

	pause();
	exit(0);
}

