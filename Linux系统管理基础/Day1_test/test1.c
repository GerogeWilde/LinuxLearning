/*************************************************************************
    > File Name: test1.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:04:55 AM CST
 ************************************************************************/

#include<stdio.h>

main()
{
	FILE * fp;
	char ch;

	if((fp = fopen("ch.txt","rt"))== NULL)
	{
		printf("\ncannot open the file,strike any key!");
		exit(1);
	}
	ch = fgetc(fp);

	while (ch!=EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
}
