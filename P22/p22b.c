/*
Name : p22b.c
Author: Patenge Kanishka
Description: Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.

20 Sept 2024
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int f;
    char *s = "FIFO22";
    mkfifo(s, S_IRWXU);
    f = open(s, O_NONBLOCK | O_WRONLY);

    if (f == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }
    char *st;
    long int size=100;
    printf("enter message\n");
    int l=getline(&st,&size,stdin);
    write(f, st, l);
    close(f);
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P22$ ./p22b
enter message
kanishka
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P22$ ./p22b
Error while opening FIFO file!: No such device or address
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P22$ ./p22b
enter message
    
*/
