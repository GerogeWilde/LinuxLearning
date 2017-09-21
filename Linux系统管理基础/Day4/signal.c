/*************************************************************************
    > File Name: signal.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 06 Jun 2017 08:56:02 AM CST
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>



void my_func(int sign_no)
{
	if(sign_no == SIGINT)
		printf("I have got SIGINT\n");
	else if(sign_no == SIGQUIT)
	{
		printf("I have got SIGQIT\n");
	}
}



void main()
{
	printf("Waiting for singnal SIGINT or SIGQUIT \n ");

	signal(SIGINT,my_func);
	signal(SIGQUIT,my_func);

	pause();
	exit(0);
}
