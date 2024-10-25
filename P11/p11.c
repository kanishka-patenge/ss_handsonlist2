/*
Name : p11.c
Author: Patenge Kanishka
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGINT signal received (%d)\n", sig);
    //printf("IGNORED..\n");
    printf("Exiting...\n");
    exit(-1);
}

int main()
{		
	struct sigaction newHandler;

	newHandler.sa_handler = sigHandler;
	newHandler.sa_flags = 0;

	sigaction(SIGINT, &newHandler, NULL); 

    while(1)
    {
        printf("Inside Loop\n");
        sleep(2);
    }

	return 0;
}

/*
Output:

======================== IGNORING ========================

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P11$ gcc p11.c -o p11
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P11$ ./p11 
Inside Loop
Inside Loop
Inside Loop
^CSIGINT signal received (2)
IGNORED..
Inside Loop
Inside Loop
^CSIGINT signal received (2)
IGNORED..
Inside Loop

======================== DEFAULT ========================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P11$ gcc p11.c -o p11
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P11$ ./p11 
Inside Loop
Inside Loop
^CSIGINT signal received (2)
Exiting...

*/

