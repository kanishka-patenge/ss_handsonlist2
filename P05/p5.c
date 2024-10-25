/*
Name : p5.c
Author: Patenge Kanishka
Description: 

Write a program to print the system limitation of
	a. maximum length of the arguments to the exec family of functions.
	b. maximum number of simultaneous process per user id.
	c. number of clock ticks (jiffy) per second.
	d. maximum number of open files
	e. size of a page
	f. total number of pages in the physical memory
	g. number of currently available pages in the physical memory.

Date: 11 Sept 2024
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("A. Maximum length of the arguments to the exec family of functions: %ld\n", sysconf(_SC_ARG_MAX));
	printf("B. Maximum number of simultaneous process per user id: %ld\n", sysconf(_SC_CHILD_MAX));
	printf("C. Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));
	printf("D. Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
	printf("E. Size of a page: %ld\n", sysconf(_SC_PAGESIZE));
	printf("F. Total number of pages in the physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
	printf("G. Number of currently available pages in the physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));
	
	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P05$ gcc p5.c -o p5

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P05$ ./p5 
A. Maximum length of the arguments to the exec family of functions: 2097152
B. Maximum number of simultaneous process per user id: 30125
C. Number of clock ticks (jiffy) per second: 100
D. Maximum number of open files: 1024
E. Size of a page: 4096
F. Total number of pages in the physical memory: 1946763
G. Number of currently available pages in the physical memory: 1226483

*/
