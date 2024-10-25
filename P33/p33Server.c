/*
Name : p33Server.c
Author: Patenge Kanishka
Description: Write a program to communicate between two machines using socket.

Date: 20 Sept 2024
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int socketFileDescriptor, connectionFileDescriptor;  
    int bindStatus;
    int listenStatus;
    int clientSize;

    struct sockaddr_in address, client;

    int readBytes, writeBytes;
    char dataFromClient[1024] = {'\0'};

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        printf("Error while creating socket!\n");
        exit(0);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1)
    {
        printf("Error while binding name to socket!\n");
        exit(0);
    }
    printf("Binding to socket was successful!\n");

    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1)
    {
        printf("Error while trying to listen for connections!\n");
        exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    clientSize = (int)sizeof(client);
    connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
    if (connectionFileDescriptor == -1)
        printf("Error while accepting a connection!\n");
    else
    {
        writeBytes = write(connectionFileDescriptor, "Hello from Server program!\n", 27);
        if (writeBytes == -1)
            printf("Error while writing to network via socket!\n");
        else
            printf("Data sent to client!\n");

        readBytes = read(connectionFileDescriptor, dataFromClient, 1024);
        if (readBytes == -1)
            printf("Error while reading from network via socket!\n");
        else
            printf("Data from client: %s\n", dataFromClient);
    }

    close(connectionFileDescriptor);

    close(socketFileDescriptor);

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P33$ gcc p33Server.c -o server
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P33$ ./server 
Server side socket successfully created!
Binding to socket was successful!
Now listening for connections on a socket!
Data sent to client!
Data from client: Hello from client program!

*/
