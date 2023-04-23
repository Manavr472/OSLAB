#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char rbuff[200];
	int fd,count;
	int p = getppid();
	fd = open("exp1.txt",O_RDWR);
	read(fd,rbuff,sizeof(rbuff));
	printf("%s \n",rbuff);
	printf("Pid for this process is %d \n",p);
	close(fd);
}
