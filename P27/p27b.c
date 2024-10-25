/*
Name : p27b.c
Author: Patenge Kanishka
Description: Write a program to receive messages from the message queue.
                        b. with IPC_NOWAIT as a flag

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
    int messageSize;

    struct msgbuf
    {
        long mtype;
        int someNumber;
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!\n");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!\n");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    data.mtype = 1;

    messageSize = msgrcv(queueIdentifier, &data, sizeof(data), data.mtype, IPC_NOWAIT);

    if (messageSize == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Received number: %d\n", data.someNumber);

    return 0;
}

/*

====================== Will Not WAIT when no msg in queue =====================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P27$ gcc p27b.c -o p27b
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P27$ ./p27b
Key: 17109698
Message Queue Identifier: 4

Error while sending message via Message Queue!
: No message of desired type

===================== Receiving msg using Practical 27 =====================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P27$ ./p27b
Key: 17109698
Message Queue Identifier: 4

Received number: 100
*/
