/*
Name : p24.c
Author: Patenge Kanishka
Description: Write a program to create a message queue and print the key and message queue id.

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
    key_t queueKey;      // Message Queue key
    int queueIdentifier; // Message Queue identifier

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | IPC_EXCL | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);

    return 0;
}
/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P24$ gcc p24.c -o p24
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P24$ ./p24 
Key: 17109656
Message Queue Identifier: 0

*/
