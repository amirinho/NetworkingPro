#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Definitions */
#define DEFAULT_BUFLEN 512
#define PORT 8080

int main()
{
int length;
    char buffer[1024];
    pid_t childpid;
    int length;
    
    /*Defining variables and creating socket for my server*/
    int serversoc =socket (AF_INET, SOCK_STREAM, 0);
    if (serversoc==-1)
    {
        perror ("Something went wrong while creating socket failed\n") ;
        exit (0) ;
         }
 
 struct sockaddr_in localserver, rmtclient;
 localserver.sin_family=AF_INET;
 localserver.sin_port=htons(PORT) ;
 localserver.sin_addr.s_addr = htonl(INADDR_ANY);
 
 length = sizeof(localserver);
  
   int b = bind(serversoc,(struct sockaddr*)&localserver, sizeof(localserver));
    if (b == -1) {
           perror("connecting to server failed\n");
           exit(0);
       }
	 
       else
           printf("Connected to client.\n");
           
       close(serversoc);
       }
      
