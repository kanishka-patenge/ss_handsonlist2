/*
Name : p8f.c
Author: Patenge Kanishka
Description:  Write a separate program using signal system call to catch the following signals.
		    f. SIGVTALRM (use setitimer system call)

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGVTALRM signal received: setitimer() function expires!\n");
    exit(-1);
}

int main()
{
	if(signal(SIGVTALRM, sigHandler) == SIG_ERR)
	{
		printf("Error!\n");
	}

    struct itimerval itTime;
    itTime.it_value.tv_sec = 5;  // Initial expiration (5 seconds)
    itTime.it_value.tv_usec = 0;
    itTime.it_interval.tv_sec = 0;  // No periodic expiration
    itTime.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &itTime, NULL);

    while(1)
    {
        printf("Inside Loop\n");
        sleep(1);
    }
    
	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ gcc p8f.c -o p8f
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P08$ ./p8f
Inside Loop
Inside Loop
Inside Loop
Inside Loop
Inside Loop
SIGVTALRM signal received: setitimer() function expires!

*/
