/*
Name : p21b.c
Author: Patenge Kanishka
Description: Write two programs so that both can communicate by FIFO - Use two way communications

Date: 19 Sept 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "fifo1" 
#define FIFO2 "fifo2" 

int main() {
    char writeMessage[100], readMessage[100];

    while (1) {
        int fd1 = open(FIFO1, O_RDONLY);
        read(fd1, readMessage, sizeof(readMessage));
        printf("Program 21a: %s\n", readMessage);
        close(fd1);

        printf("Program 21b: Enter message: ");
        fgets(writeMessage, sizeof(writeMessage), stdin);

        int fd2 = open(FIFO2, O_WRONLY);
        write(fd2, writeMessage, strlen(writeMessage) + 1);
        close(fd2);
    }
    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P21$ ./p21b
Program 21a: Hello from P21a

Program 21b: Enter message: Hi from P21b

*/
