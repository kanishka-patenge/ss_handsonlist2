/*
Name : p31a.c
Author: Patenge Kanishka
Description: Write a program to create a semaphore and initialize value to the semaphore.
                        a. create a binary semaphore

Date: 20 Sept 2024
*/

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    int semKey;
    int semIndentifier;
    int semctlStatus;

    union semun {
        int val;
    } semSet;

    semKey = ftok(".", 1);
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

    semSet.val = 1; // 1 -> Binary Semaphore

    semctlStatus = semctl(semIndentifier, 0, SETVAL, semSet);

    if(semctlStatus == -1) {
        printf("Error while initalizing semaphore!\n");
        exit(0);
    }

    return 0;
}


/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ gcc p31a.c -o ./p31a 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ ./p31a 
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P31$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x0105129d 1          kanishka     777        1         

*/
