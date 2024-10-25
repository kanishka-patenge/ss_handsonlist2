/*
Name : p8a.c
Author: Patenge Kanishka
Description: Write a separate program using signal system call to catch the following signals.
			a. SIGSEGV
Date: 12 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void sigHandler(int sig)
{
	if(sig == SIGSEGV)
	{
		printf("SIGSEGV: Invalid Memory Reference!\n");
		exit(1);
	}
		
	else
		printf("Invalid Signal!\n");
}

struct Node
{
	int data;
	struct Node *next;
};

int main()
{

	if(signal(SIGSEGV, sigHandler) == SIG_ERR)
	{
		printf("Error!\n");
	}
	
	struct Node *head;
	head->data = 1;
	head->next = NULL;

	head = head->next->next;
	
	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ ./p8a
SIGSEGV: Invalid Memory Reference!

*/
