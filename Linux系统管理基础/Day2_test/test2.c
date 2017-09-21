/*************************************************************************
    > File Name: test2.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:41:03 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	int count = 0;

	pid = fork();

	if(0 == pid)
	{
		count++;
		printf("count1 = %d.\n",count);
	}

	else 
	{
		printf("count_parent  = %d.\n",count);
	}
	printf("count2 = %d.\n",count);
	return 0;
}
