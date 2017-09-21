/*************************************************************************
    > File Name: file_cp.c
    > Author: Qiao xu
    > Mail: GerogeWilde123@gmail.com
    > Created Time: Tue 04 Jul 2017 08:36:37 AM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024


int main(int argc,char *argv[])
{
	int from_fd;
	int to_fd;
	int bytes_read,bytes_write;
	char buffer[BUFFER_SIZE];
	char *ptr;
	
	/***************************** Creat file *****************************/
	if(3 != argc){
		fprintf(stderr,"Usage:%s fromfile to file\n\a",argv[0]);
	}

	if(-1 == (from_fd = fopen(argv[1],"rt"))){
		fprintf(stderr,"Open %s Error:%s\n",argv[1],strerror(errno));
		exit(1);
	}

	if(-1 == (to_fd = fopen(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))){
		fprintf(stderr,"Open %s Error:%s\n",argv[2],strerror(errno));
	}

	/******************************  Copy file ******************************/
	while(bytes_read = fread(ptr,BUFFER_SIZE,1,from_fd)){
		if((bytes_read == -1) && (errno != EINTR)) break;
		else if(bytes_read>0){
			ptr = buffer;
			while(bytes_write = fwrite(ptr,bytes_read,1,to_fd)){
				if((bytes_write == -1)&& (errno !=EINTR)) break;
				else if(bytes_write == bytes_read) break;
				else if(bytes_write >0){
					ptr += bytes_write;
					bytes_read -= bytes_write;
				}
			}
			if(bytes_write == -1) break;
		}
	}

	close(from_fd);
	close(to_fd);
	exit(0);
}
