#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<string.h>
#include <errno.h>

int main(void)
{
  printf("________________________________________\n");
  printf("|                                      |\n");
  printf("|    welcome to IPC program by WHY!    |\n");
  printf("|     enter r to receive messages      |\n");
  printf("|         or enter q to quit           |\n");
  printf("|______________________________________|\n\n");


    int fifo;
    char data[1000],input;
    while(1)
    {
    printf("please input command:");
    scanf("%c",&input);
    getchar();
    if(input=='r')
    {
      if(access("fifo1",F_OK)==-1)
      {
        printf("error:no such a fifo.\nMaybe the message haven't been sent.\nplease wait for the message sending.\n");
        exit(EXIT_FAILURE);
        return 0;
      }
      if((fifo=open("fifo1",O_RDONLY))==-1)
    	{
    		printf("Open FIFO Failed\n");
    		exit(EXIT_FAILURE);
    	}
    	if(read(fifo,data,999)==-1)
      {
        printf("Read FIFO Failed\n");
    		exit(EXIT_FAILURE);
      }
      data[1000]='\0';
    	printf("Read message: %s",data);
    	close(fifo);
      unlink("fifo1");
    }
    else break;
  }
	return 0;
}
