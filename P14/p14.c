/*
Name : p14.c
Author: Patenge Kanishka
Description: Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.

Date: 18 Sept 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{		
	// File descriptor used for pipe operations
    int pipefd[2];                // pipefd[0] -> read, pipefd[1] -> write
    char *writeBuffer = "Practical 14: creating pipe, and writing into the pipe\n"; // Data sent through the pipe
    char *readBuffer;
    int pipeStatus;
    int readBytes, writeBytes;

    // Creating a pipe
    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the pipe! ");
    else
    {
        printf("Writing to the pipe!\n");
        writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
        if (writeBytes == -1)
            perror("Error while writing to pipe!");
        else
        {
            printf("Now reading from the pipe!\n");
            readBytes = read(pipefd[0], &readBuffer, writeBytes);
            if (readBytes == -1)
                perror("Error while reading from pipe!");
            else
                printf("Data from pipe: %s\n", readBuffer);
        }
    }
    

	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P14$ gcc p14.c -o p14
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P14$ ./p14 
Writing to the pipe!
Now reading from the pipe!
Data from pipe: Practical 14: creating pipe, and writing into the pipe

*/
