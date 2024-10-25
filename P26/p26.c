/*
Name : p26.c
Author: Patenge Kanishka
Description: Write a program to send messages to the message queue. Check $ipcs -q

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
    int messageSendStatus;

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
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Message sent!\n");

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P26$ gcc p26.c -o p26
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P26$ ./p26 
Key: 17109652
Message Queue Identifier: 2

Message sent!
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051294 2          kanishka     700        16           1          

*/
