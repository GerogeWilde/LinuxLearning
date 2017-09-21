/*************************************************************************
    > File Name: test2.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:12:13 AM CST
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int i;
	printf("input an interger:");
	if(fscanf(stdin,"%d",&i))
		printf("The ineger read was:%d\n",i);
	return 0;
}
