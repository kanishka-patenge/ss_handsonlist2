/*
Name : p10b.c
Author: Patenge Kanishka
Description: Write a separate program using sigaction system call to catch the following signals
        b. SIGINT

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGINT signal received (%d)\n", sig);
}

struct Node{
	int data;
	struct Node *next;
};

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

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ gcc p10b.c -o p10b
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ ./p10b
Inside Loop
Inside Loop
^CSIGINT signal received (2)
Inside Loop
^CSIGINT signal received (2)
Inside Loop
Inside Loop

*/

