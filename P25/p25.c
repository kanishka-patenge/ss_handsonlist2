/*
Name : p25.c
Author: Patenge Kanishka
Description: Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                        a. access permission
                        b. uid, gid
                        c. time of last message sent and received
                        d. time of last change in the message queue
                        d. size of the queue
                        f. number of messages in the queue
                        g. maximum number of bytes allowed
                        h. pid of the msgsnd and msgrcv

Date: 19 Sept 2024
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    key_t queueKey;
    int queueIdentifier;
    struct msqid_ds queueInfo;
    int msgctlStatus;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &queueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %od\n", queueInfo.msg_perm.mode);
    printf("UID: %d\n", queueInfo.msg_perm.uid);
    printf("GID: %d\n", queueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n", queueInfo.msg_stime);
    printf("Time of last message received: %ld\n", queueInfo.msg_rtime);
    printf("Size of queue: %ld\n", queueInfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", queueInfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", queueInfo.msg_qbytes);
    printf("PID of last sent message: %d\n", queueInfo.msg_lspid);
    printf("PID of last received message: %d\n", queueInfo.msg_lrpid);

    return 0;
}

/*

Key: 17106853
Message Queue Identifier: 0

Access Permission: 700d
UID: 1000
GID: 1000
Time of last message sent: 0
Time of last message received: 0
Size of queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last sent message: 0
PID of last received message: 0

*/
