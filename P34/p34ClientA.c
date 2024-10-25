/*
Name : p34ClientA.c
Author: Patenge Kanishka
Description: Write a program to create a concurrent server.
                        a. use fork

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
    int socketFileDescriptor;
    int connectStatus;

    struct sockaddr_in address;

    int readBytes, writeBytes;
    char dataFromServer[1024] = {'\0'};

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        printf("Error while creating socket!\n");
        exit(0);
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        printf("Error while connecting to server!\n");
        exit(0);
    }
    printf("Client to serrver connection successfully established!\n");

    readBytes = read(socketFileDescriptor, dataFromServer, 100);

    if (readBytes == -1)
        printf("Error while reading from network via socket!\n");
    else
        printf("Data from server: %s\n", dataFromServer);

    writeBytes = write(socketFileDescriptor, "Hello from client\n", 19);
    if (writeBytes == -1)
        printf("Error while writing to network via socket!\n");
    else
        printf("Data sent to server!\n");
    

    close(socketFileDescriptor);

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P34$ gcc p34ClientA.c -o ClientA
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P34$ ./ClientA 
Client side socket successfully created!
Client to serrver connection successfully established!
Data from server: Hello from Server!

Data sent to server!

*/
