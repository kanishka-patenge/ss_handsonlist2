/*
Name : p20b.c
Author: Patenge Kanishka
Program Description: Write two programs so that both can communicate by FIFO - Use one way communication.

Date: 19 Sept 2024
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    int fileDescriptor;
    char *fifoFile = "./FIFO_File";
    int readBytes;
    char data[100];

    fileDescriptor = open(fifoFile, O_RDONLY);

    if (fileDescriptor == -1)
        perror("Error: \n");
    else
    {
        readBytes = read(fileDescriptor, data, 100);
        if (readBytes == -1)
            perror("Error: \n");
        else
        {
            printf("Read bytes : %d\n", readBytes);
            printf("Data from the FIFO file - %s\n", data);
        }
        close(fileDescriptor);
    }

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P20$ ./p20b
Read bytes : 34
Data from the FIFO file - Hello from 20a.c program to 20b.c

*/
