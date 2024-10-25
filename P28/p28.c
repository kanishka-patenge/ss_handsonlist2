/*
Name : p28.c
Author: Patenge Kanishka
Description: Write a program to change the exiting message queue permission. (use msqid_ds structure)

Date: 20 Sept 2024
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
    key_t queueKey;                   
    int queueIdentifier;              
    struct msqid_ds messageQueueInfo;
    int msgctlStatus;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        printf("Error while computing key!\n");
        exit(-1);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        printf("Error while creating Message Queue!\n");
        exit(-1);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        printf("Error while getting Message Queue info!\n");
        exit(-1);
    }

    printf("Current Permission: %d\n", messageQueueInfo.msg_perm.mode);

    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    printf("Updated Permission: %d\n", messageQueueInfo.msg_perm.mode);

    msgctlStatus = msgctl(queueIdentifier, IPC_SET, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        printf("Error while changing Message Queue permission!");
        exit(0);
    }

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P28$ gcc p28.c -o p28
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P28$ ./p28 
Key: 17105838
Message Queue Identifier: 0
Current Permission: 511
Press enter to change the permissions!

Updated Permission: 448

*/
