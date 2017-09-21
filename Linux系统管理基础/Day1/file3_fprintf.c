/*************************************************************************
    > File Name: file3_fprintf.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 16 May 2017 08:35:57 AM CST
 ************************************************************************/

#include<stdio.h>

FILE *stream;

void main()
{
	int i = 10;
	double fp = 1.5;
	char s[] = "To be honest";
	char c = '\n';

	stream = fopen("fprint.out","w");
	fprintf(stream,"%s%c",s,c);

	//int fprintf(FILE *stream, const char *format, ...);
	
	//Return value:Upon successful return, these functions return the number	 
	//of characters printed  (not  including  the  trailing  '\0'  used  to  e	nd  output to	  //strings)

	fprintf(stream,"%d\n",i);
	fprintf(stream,"%f\n",fp);
	fclose(stream);
}

