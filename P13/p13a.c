/*
Name : p13a.c
Author: Patenge Kanishka
Description: 

Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
Find out whether the first program is able to catch the signal or not

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{		

    printf("Hello from program 1 and PID: %d\n", getpid());

    for(;;);

	return 0;
}
