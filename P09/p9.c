/*
Name : p9.c
Author: Patenge Kanishka
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT. signal - Use signal system call.

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigHandler(int sig)
{
	printf("SIGINT: Terminal Interrupt!\n");
//	printf("Exiting...\n");
//    exit(1);
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

=================== Ignoring the SIGINT =================== 

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P09$ gcc p9.c -o p9
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P09$ ./p9 
Inside Loop
Inside Loop
Inside Loop
^CSIGINT: Terminal Interrupt!
Inside Loop
Inside Loop
^CSIGINT: Terminal Interrupt!
Inside Loop

=================== Default ===================
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P09$ gcc p9.c -o p9
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P09$ ./p9 
Inside Loop
Inside Loop
Inside Loop
^CSIGINT: Terminal Interrupt!
Exiting...


*/

