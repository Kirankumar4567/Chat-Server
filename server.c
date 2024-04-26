#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	mkfifo("cs",0666);
	mkfifo("c1",0666);
	mkfifo("c2",0666);
	mkfifo("c3",0666);
	while(1)
	{
		char msg[20];
		int fd=open("cs",O_RDONLY);
		read(fd,msg,20);
		close(fd);
		for(int i=0;i<strlen(msg);i++)
		printf("%c",msg[i]);
		//printf("ok\n");
		int fd1=open("c1",O_WRONLY);
		int fd2=open("c2",O_WRONLY);
		int fd3=open("c3",O_WRONLY);
			//printf("s is writring into 1 msg as %s\n",msg);
			write(fd1,msg,strlen(msg)+1);
			close(fd1);
			//printf("s is writring into 2 msg as %s\n",msg);
			write(fd2,msg,strlen(msg)+1);
			close(fd2);
			write(fd3,msg,strlen(msg)+1);
			close(fd3);
	}
     return 0;
}
