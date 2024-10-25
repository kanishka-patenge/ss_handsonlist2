/*
Name : p31b.c
Author: Patenge Kanishka
Description: Write a program to create a semaphore and initialize value to the semaphore.
                        b. create a counting semaphore

Date: 20 Sept 2024
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int semKey;
    int semIndentifier;
    int semctlStatus;

    union semun {
        int val;
    } semSet;

    semKey = ftok(".", 3);
    if (semKey == -1)
    {
        printf("Error while computing key!\n");
        exit(1);
    }

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if(semIndentifier == -1) {
        printf("Error while creating semaphore!\n");
        exit(1);
    }

    semSet.val = 5; // 5 -> Counting Semaphore

    semctlStatus = semctl(semIndentifier, 0, SETVAL, semSet);

    if(semctlStatus == -1) {
        printf("Error while initalizing semaphore!\n");
        exit(0);
    }

    return 0;
}


/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ gcc p31b.c -o ./p31b 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ ./p31b
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x0105129d 2          kanishka     777        1         

*/
