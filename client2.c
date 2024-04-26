#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	//int c=0;
	//printf("ok\n");
	mkfifo("c2",0666);
	
	//mkfifo("",0666);//user to server
	mkfifo("cs",0666);//common server
	
	int c=fork();
	if(c>0)
	{
		while(1){
			//char user[20];
			//printf("enter username:\n");
			//fgets(user,20,stdin);
			//int fd=open("utos",O_WRONLY);
			//write(fd,user,strlen(user));
			//close(fd);
			//printf("c2 enter msg: \n");
			char msg[20];
			fgets(msg,20,stdin);
			//printf("c2 msg is: %s\n",msg);
			char user[20]="c2 : ";
			strcat(user,msg);
			int fd=open("cs",O_WRONLY);
			write(fd,user,strlen(user)+1);
			close(fd);
			}
		
	}
	else
	{
	//printf("ok1\n");
	while(1){
		       mkfifo("c2",0666);
			char rdmsg[20];
			int fd=open("c2",O_RDONLY);
			//printf("c2 reading: \n");
			read(fd,rdmsg,20);
			printf("   %s\n",rdmsg);
			close(fd);
			}
		
	}
	
}
