/*
Name : p23.c
Author: Patenge Kanishka
Description: Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<errno.h>

int main()
{	
    char *fifoName = "FIFO_file";
    int fifoStatus = mkfifo(fifoName, S_IRWXU);

    if (!(errno == EEXIST || fifoStatus != -1))
        printf("Error while creating FIFO file!");
    else
    {
        long maxFiles = sysconf(_SC_OPEN_MAX);

        if (maxFiles == -1)
        {
            printf("Error while calling sysconf!\n");
            exit(-1);
        }
        else
            printf("Maximum number of files that can be opened is: %ld\n", maxFiles);

        long sizeOfPipe = pathconf(fifoName, _PC_PIPE_BUF);

        if (sizeOfPipe == -1)
        {
            printf("Error while calling pathconf!");
            exit(1);
        }
        else
            printf("Maximum size of pipe: %ld\n", sizeOfPipe);
    }

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P23$ gcc p23.c -o p23
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P23$ ./p23 
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 4096

*/
