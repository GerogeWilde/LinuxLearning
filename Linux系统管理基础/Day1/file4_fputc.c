/*************************************************************************
    > File Name: file4_fputc.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 16 May 2017 09:21:35 AM CST
 ************************************************************************/

#include<stdio.h>

main()
{
	FILE *fp;
	char ch;
	if((fp = fopen("string","w+")) == NULL){
		printf("Cannot open file,strike any key to exit!");
		exit(1);
	}
	printf("input a string:\n");
	ch = getchar();
	while(ch != '\n'){
		fputc(ch);
	}
}
