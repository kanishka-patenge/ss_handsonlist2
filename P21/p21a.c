/*
Name : p21a.c
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
    if (mkfifo(FIFO1, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    if (mkfifo(FIFO2, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    char writeMessage[100], readMessage[100];

    while (1) {
        printf("Program 21a: Enter message: ");
        fgets(writeMessage, sizeof(writeMessage), stdin);

        int fd1 = open(FIFO1, O_WRONLY);
        write(fd1, writeMessage, strlen(writeMessage) + 1);
        close(fd1);

        int fd2 = open(FIFO2, O_RDONLY);
        read(fd2, readMessage, sizeof(readMessage));
        printf("Program 21b: %s\n", readMessage);
        close(fd2);
    }

    return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P21$ ./p21a
Program 21a: Enter message: Hello from P21a    
Program 21b: Hi from P21b

*/
