/*
Name : p32c.c
Author: Patenge Kanishka
Description: Write a program to implement semaphore to protect any critical section.
                        c. protect multiple pseudo resources ( may be two) using counting semaphore

Date: 20 Sept 2024
*/

#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    char *filename = "./tempC.txt";

    int fileDescriptor;
    int readBytes;
    int lseekOffset;
    char data[1000];

    int semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    fileDescriptor = open(filename, O_CREAT | O_RDONLY);
    if (fileDescriptor == -1)
    {
        printf("Error while creating / opening the ticket file!\n");
        exit(0);
    }

    union semun
    {
        int val;
    } semSet;

    semKey = ftok(".", 331);
    if (semKey == -1)
    {
        printf("Error while computing key!\n");
        exit(1);
    }

    semIdentifier = semget(semKey, 1, 0);
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);
        if (semIdentifier == -1)
        {
            printf("Error while creating semaphore!\n");
            exit(1);
        }

        semSet.val = 2;
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            printf("Error while initializing a binary sempahore!\n");
            exit(1);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }

    printf("Obtained lock on critical section!\n");

    printf("Now entering critical section!\n");

    readBytes = read(fileDescriptor, &data, 1024);
    if (readBytes == -1)
    {
        printf("Error while reading from sample file!\n");
        exit(0);
    }
    else if (readBytes == 0)
        printf("No data exists!\n");
    else
        printf("Sample data: \n %s", data);

    printf("\n\nPress enter key to exit critical section!\n");
    getchar();

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }

    close(fileDescriptor);

    return 0;
}


/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ sudo echo "My name is kanishka" >> tempC.txt 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ gcc p32c.c -o p32c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ ./p32c
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
Sample data: 
 My name is kanishka
��

Press enter key to exit critical section!

*/
