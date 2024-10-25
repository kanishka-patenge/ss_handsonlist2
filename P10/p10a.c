/*
Name : p10a.c
Author: Patenge Kanishka
Description: Write a separate program using sigaction system call to catch the following signals
        a. SIGSEGV

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGSEGV (Invalid memory reference) Signal received!\n");
    exit(0);
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

	sigaction(SIGSEGV, &newHandler, NULL); 

	
	struct Node *head;
	head->data = 1;
	head->next = NULL;

	head = head->next->next;

	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ gcc p10a.c -o p10a
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ ./p10a 
SIGSEGV (Invalid memory reference) Signal received!

*/

