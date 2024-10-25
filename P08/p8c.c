/*
Name : p8c.c
Author: Patenge Kanishka
Description:  Write a separate program using signal system call to catch the following signals.
			c. SIGFPE

Date: 16 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("FPE: Floating point exception!\n");
    exit(-1);
}

int main()
{
	if(signal(SIGFPE, sigHandler) == SIG_ERR)
	{
		printf("Error!\n");
	}

    int x = 3/0;

	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ gcc p8c.c -o p8c
p8c.c: In function ‘main’:
p8c.c:28:14: warning: division by zero [-Wdiv-by-zero]
   28 |     int x = 3/0;
      |              ^
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ ./p8c
FPE: Floating point exception!

*/
