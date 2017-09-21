/*************************************************************************
    > File Name: test3.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 20 Jun 2017 08:17:11 AM CST
 ************************************************************************/

#include<stdio.h>

FILE *stream;

void main()
{
	int i = 10;
	double fp = 1.5;
	char s[] = "to be honest";
	char c = '\n';

	stream = fopen("fprintf.out","w");
	fprintf(stream,"%s%c",s,c);

	fprintf(stream,"%d\n",i);
	fprintf(stream,"%f\n",fp);
	fclose(stream);
}
