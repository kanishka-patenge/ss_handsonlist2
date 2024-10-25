/*
Name : p30.c
Author: Patenge Kanishka
Description: Write a program to create a shared memory.
                        a. write some data to the shared memory
                        b. attach with O_RDONLY and check whether you are able to overwrite.
                        c. detach the shared memory
                        d. remove the shared memory

Date: 20 Sept 2024
*/


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int shmKey;
    int shmIdentifier;
    int shmSize = 40;
    char *shmPointer, *rdOnlyShmPointer;

    shmKey = ftok(".", 1);

    if (shmKey == -1)
    {
        printf("Error while computing key!\n");
        exit(0);
    }

    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700);

    if (shmIdentifier == -1)
    {
        printf("Error while getting Shared Memory!");
        exit(0);
    }

    shmPointer = shmat(shmIdentifier, (void *)0, 0);

    if (*shmPointer == -1)
    {
        printf("Error while attaching address space!");
        exit(0);
    }

    printf("Press enter to write to the shared memory!\n");
    getchar();

    sprintf(shmPointer, "Hello, How are you?");

    printf("Press enter to read from the shared memory!\n");
    getchar();

    // Reading from the shared memory
    printf("Data from shared memory: %s\n", shmPointer);


    rdOnlyShmPointer = shmat(shmIdentifier, (void *)0, SHM_RDONLY);
    if (*rdOnlyShmPointer == -1)
    {
        printf("Error while attaching address space!");
        exit(0);
    }
    
    // printf("Press enter to write to the shared memory!\n");
    // getchar();

    // Writing to the shared memory
    // sprintf(rdOnlyShmPointer, "Overwriting into the shared memory\n");

    printf("Detaching pointer to shared memory!\n");
    shmdt(shmPointer);
    shmdt(rdOnlyShmPointer);


    printf("Press enter to delete the shared memory!\n");
    getchar();

    shmctl(shmIdentifier, IPC_RMID, NULL);

    return 0;
}

/*

====================== Reading =======================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P30$ gcc p30.c -o p30
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P30$ ./p30 
Press enter to write to the shared memory!

Press enter to read from the shared memory!

Data from shared memory: Hello, How are you?
Detaching pointer to shared memory!
Press enter to delete the shared memory!

====================== Writing =======================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P30$ gcc p30.c -o p30
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P30$ ./p30 
Press enter to write to the shared memory!

Press enter to read from the shared memory!

Data from shared memory: Hello, How are you?
Press enter to write to the shared memory!

Segmentation fault (core dumped)

*/
