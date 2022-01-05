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
    int server =socket (AF_INET, SOCK_STREAM, 0);
     if (server==-1)
    {
       perror ("Something went wring while creating socket failed\n") ;
        exit code (0);
         }
    
