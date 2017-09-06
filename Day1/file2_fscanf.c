/*************************************************************************
    > File Name: file2_fscanf.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 16 May 2017 09:04:53 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i;
	printf("Input an interger:");
	if(fscanf(stdin,"%d",&i))    //?-stdin
		printf("The ineger read was;%d\n",i);
	return 0;
}
