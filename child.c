#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#define   MAX_COUNT  5

void  ChildProcess(void);                /* child process prototype  */
void  main(void)
{
     int pidwait,child_status;
     int p_pid = getppid();
     int c_pid = getpid();
     printf("child pid: %d \n parent pid: %d \n",c_pid,p_pid);
     if (fork() == 0){ 
          ChildProcess();
          }
     else{
          pidwait = wait(&child_status);
          printf("Child %d has terminated \n",pidwait);
          }
     exit(0);
}
void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
     printf("child process id: %d \n ",getpid());
}