/*
Name : p32d.c
Author: Patenge Kanishka
Description: Write a program to implement semaphore to protect any critical section.
                        d. remove the created semaphore

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

    semKey = ftok(".", 1);
    if (semKey == -1)
    {
        printf("Error while computing key!");
        exit(1);
    }

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if (semIndentifier == -1)
    {
        printf("Error while creating semaphore!");
        exit(1);
    }

    printf("Press enter to delete the semaphore!\n");
    getchar();

    semctlStatus = semctl(semIndentifier, 0, IPC_RMID);

    if (semctlStatus == -1)
    {
        printf("Error while deleting semaphore!");
        exit(0);
    }

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ gcc p32d.c -o p32d
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x4b05133c 0          kanishka     700        1         
0x0105133c 2          kanishka     777        1         


kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ ./p32d
Press enter to delete the semaphore!

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P32$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x4b05133c 0          kanishka     700        1       

*/
