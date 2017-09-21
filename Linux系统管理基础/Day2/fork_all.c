#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>  //refer to the errno
#include <math.h>	//refer to the sin()

/* 进程创建 */
void main(void)
{
	pid_t child;
	int status;

	printf("This will demostrate how to get child status\n");

/*
 On  success, the PID of the child process is returned in the
parent, and 0 is returned in the child.  On failure,  -1  is
returned  in  the  parent,  no child process is created, and
errno is set appropriately.
*/

	/* 创建子进程 */
	if((child=fork())==-1)
	{
		printf("Fork Error : %s\n", strerror(errno));
		//strerror, strerror_r - return string describing error number
		//errno is the key of the whole project
		exit(1);
	}
	else if(child==0) // 子进程
	{
		int i;

/*
getpid()  returns  the  process  ID  of the calling process.
(This is often used by routines that generate unique  tempo‐
rary filenames.)
*/
		printf("I am the child: %s\n", getpid());
		for(i=0;i<1000000;i++) sin(i);
		i=5;
		printf("I exit with %d\n", i);
		exit(i);
	}

	while(((child=wait(&status))==-1)&(errno==EINTR));  //子进程未结束

/*
wait()--->value
The value of pid can be:

< -1   meaning wait for  any  child  process  whose  process
       group ID is equal to the absolute value of pid.

-1     meaning wait for any child process.

0      meaning  wait  for  any  child  process whose process
	   group ID is equal to that of the calling process.

> 0    meaning wait for the child whose process ID is  equal
	   to the value of pid.
*/


	if(child==-1)
		printf("Wait Error: %s\n", strerror(errno));
	else if(!status)             // 子进程退出值为0
		printf("Child %ld terminated normally return status is zero\n", child);
	else if(WIFEXITED(status))   // 子进程退出值0
		printf("Child %ld terminated normally return status is %d\n", child, WEXITSTATUS(status));
	else if(WIFSIGNALED(status)) // 子进程未获信号而退出
		printf("Chlid %ld terminated due to signal %d not caught\n", child, WTERMSIG(status));
}	
