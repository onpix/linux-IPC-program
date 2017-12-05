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
    printf("|       enter s to send messages       |\n");
    printf("|         or enter q to quit           |\n");
    printf("|______________________________________|\n\n");
    printf("attention:if the message is not recieved ,the program will keep on waiting.\n");

    char input;
    int fifo,p,i;
    char data[1000];
    while(1)
    {
      printf("please input command:");
      scanf("%c",&input);
      if(input=='s')
      {
          getchar();
          printf("input the messages you want to send:\n");
          for(i=0;i<1000;i++)
          {
            data[i]=getchar();
            if(data[i]=='\n')
              break;
          }
          data[i+1]='\0';
        if(access("fifo1",F_OK)==-1)
        {
            p=mkfifo("fifo1",0777);
            if(p!=0)
            {
                printf("can not create the FIFO.\n");
                exit(EXIT_FAILURE);
            }

          fifo=open("fifo1",O_WRONLY);
          if(fifo==-1)
          {
            printf("open FIFO Failed.error message:%s\n",strerror(errno));
            close(fifo);
            exit(EXIT_FAILURE);
          }

          if(write(fifo,data,1000)==-1)
              {
                  printf("Write FIFO Failed\n");
                  close(fifo);
                  exit(EXIT_FAILURE);
              }
        }
        else
        {
          printf("the fifo maybe has been created.please try again.\n\n");
          unlink("fifo1");
        }
      }
      else
        break;
    }
    return 0;
}
