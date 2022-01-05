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
#define PORT 5000

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
  
   int b = connect(serversoc,(struct sockaddr*)&localserver, sizeof(localserver));
    if (b == -1) {
           perror("connecting to server failed\n");
           exit(0);
       }
	 
       else
           printf("Connected to server.\n");
	/*method to get and put file fron and on the server*/

    char get = "GET";
    char put = "PUT";
    int l;
      recv (serversoc,&l, 4, 0) ;
      char msg[l];
      int k=recv(serversoc, msg, sizeof (msg) , 0) ;
      msg[k]='\0';
      printf("%s\n", msg);
      char fname[20];
      printf("Enter file name to request from server:");
      scanf("%s",get, fname );
      send (serversoc,fname, strlen(fname),0);
      printf("File name successful sent\n");
    
    int p4;
     recv(serversoc, &p4, 4, 0);
     char msg2[p4] ;
     int k1=recv(serversoc, msg2, sizeof (msg2) , 0);
     msg2[k1]='\0';
     printf("File received", msg2) ;
     printf("In File size is %d\n",p4);
     char fnamel[20];
     printf("Enter new file name:");
     scanf("%s", put, fnamel);
     FILE *fp=fopen(fnamel,"w");
     fwrite(msg2,1, p4, fp);
     fclose(fp);
     printf( "File successfuly transferred and created/n");
    
    
    close(serversoc);
       



}
      

       close(serversoc);
       }
      
