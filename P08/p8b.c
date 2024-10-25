/*
Name : p8b.c
Author: Patenge Kanishka
Description:  Write a separate program using signal system call to catch the following signals.
			b. SIGINT

Date: 12 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGINT: Terminal Interrupt!\n");
}

int main()
{
	if(signal(SIGINT, sigHandler) == SIG_ERR)
	{
		printf("Error!\n");
	}

	while(1)
	{
		printf("Inside Loop\n");
		sleep(2);
	}

	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ gcc p8b.c && p8b
Inside Loop
Inside Loop
^CSIGINT: Terminal Interrupt!
Inside Loop
Inside Loop
Inside Loop
Inside Loop
Inside Loop
^CSIGINT: Terminal Interrupt!
Inside Loop

*/
