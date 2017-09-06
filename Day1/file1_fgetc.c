/*************************************************************************
    > File Name: file1.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 16 May 2017 08:07:42 AM CST
 ************************************************************************/

#include<stdio.h>

main()
{
	FILE * fp;		//   description 
	char ch;

	if((fp = fopen("c1.txt","rt")) == NULL)
	{
		printf("\nCannot open file ,strike any key exit!");
		exit(1);
	}
	ch = fgetc(fp);
	//fgetc() reads the next character from  stream  and  returns  it  as  an
	//unsigned char cast to an int, or EOF on end of file or error.
	
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);

}
