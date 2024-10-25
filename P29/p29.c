/*
Name : p29.c
Author: Patenge Kanishka
Description: Write a program to remove the message queue.

Date: 20 Sept 2024
*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<stdlib.h>

int main()
{
    key_t queueKey;
    int queueIdentifier;
    int msgctlStatus;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        printf("Error while computing key!\n");
        exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        printf("Error while creating Message Queue!\n");
        exit(0);
    }

    printf("Message Queue Identifier: %d\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_RMID, NULL);

    if (msgctlStatus == -1)
    {
        printf("Error while removing Message Queue\n");
        exit(0);
    }

    printf("Message Queue Removed\n");

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P29$ gcc p29.c -o p29
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P29$ ./p29
Message Queue Identifier: 4
Message Queue Removed

*/
