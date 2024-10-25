/*
Name : p10c.c
Author: Patenge Kanishka
Description: Write a separate program using sigaction system call to catch the following signals
        c. SIGFPE

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGFPE signal received (%d)\n", sig);
    exit(-1);
}

int main()
{		
	struct sigaction newHandler;

	newHandler.sa_handler = sigHandler;
	newHandler.sa_flags = 0;

	sigaction(SIGFPE, &newHandler, NULL); 

    int x = 3 / 0;

	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ gcc p10c.c -o p10c
p10c.c: In function ‘main’:
p10c.c:30:15: warning: division by zero [-Wdiv-by-zero]
   30 |     int x = 3 / 0;
      |               ^
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P10$ ./p10c
SIGFPE signal received (8)

*/

