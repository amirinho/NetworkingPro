//
//  main.c
//  amirsocketC
//
//  Created by admin on 1.01.2022.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 1024
#define PORT 5000


int main()
{
    /*Defining variable and creating socket for my server, i choose to work with Tcp which socket argument is defined as 0 in the socket function*/
    int serversoc =socket (AF_INET, SOCK_STREAM, 0);
     if (serversoc==-1)
    {
       perror ("Something went wring while creating socket failed\n") ;
        exit code (0);
         }
    /* Assigning port and adress to my structure*/
     struct sockaddr_in localserver, client;
     localserver.sin_family=AF_INET;
     localserver.sin_port=htons(PORT) ;
     localserver.sin_addr.s_addr = htonl(INADDR_ANY);
    
    /*Binding my server socket with addresses*/
 int b = bind(serversoc,(struct sockaddr*)&localserver, sizeof(localserver));
    if (b==-1) {
        perror("Unable to bind socket with address\n");
        exit(0); 
    }
          /* Activating my socket to listen to connecttions*/
      if ((listen(serversoc, 5)) == -1) {
            perror("Unable to Listen \n");
            exit(0);
        }
       /*Accepting connections from clients and closing sockets*/
     length = sizeof(rmtclient);
       int con = accept(serversoc,(struct sockaddr*)&rmtclient, &length);
       if (con ==-1) {
           perror("server failed to accept\n");
           exit(0);
       }
       else
           printf("server accepted connection from client.\n");
      
/*fork system to handle multiple clients*/
      if((childpid = fork()) == 0){
                    close(serversoc);
        
        /*method to send and receive data from the client*/
      
        int k,p,l1,l2;
        
        system ("List>a.txt") ;
        char str[50];
        char *msg="";
        FILE *fp=fopen("b.txt", "r");
        msg= (char*) malloc(1);
while(fgets (str,50, fp)!=NULL)
        {
            l1= strlen(str);
            l2= strlen(msg);
            
            msg =(char *) realloc (msg, l1+l2);
            strcat(msg,str);
            fclose(fp);
             int s=strlen(msg);
             send (con,&s,4,0);
             send (con,msg,strlen(msg),0);
            
            char fname[20];
             int f1=recv(con, fname, sizeof (fname) , 0) ;
             fname[f1]='\0';
            printf ("File request' received from client is%s\n", fname);
            fp = fopen(fname, "r");
            
    
            msg= (char*) malloc(1);
    while(fgets (str,50, fp)!=NULL)
            {
                l1= strlen(str);
                l2= strlen(msg);
                
                msg =(char *) realloc (msg, l1+l2);
                strcat(msg,str);
            }
                int p3=strlen(msg);
            
             send (con,&p3,4,0);
             send (con,msg,strlen(msg),0);
            printf("File trasnmitted to client/n");
        
        
            
               
                 }
            }
}
}
