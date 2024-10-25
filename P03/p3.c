/*
Name : p3.c
Author: Patenge Kanishka
Description: Write a program to set (any one) system resource limit. Use setrlimit system call.

Date: 11 Sept 2024
*/

#include<stdio.h>
#include<sys/resource.h>

int main()
{
	struct rlimit resourceLimit;

	printf("====== Currently size of the process stack, in bytes ======\n");
	getrlimit(RLIMIT_STACK, &resourceLimit);

	printf("Current: %ld\n", resourceLimit.rlim_cur);
//	printf("Maximum: %ld\n", resourceLimit.rlim_max);

	// Updating process stack limit
	resourceLimit.rlim_cur = 10000;
	resourceLimit.rlim_max = 20000;
	
	setrlimit(RLIMIT_STACK, &resourceLimit);

	printf("====== Updated size of the process stack, in bytes ======\n");
	printf("Current: %ld\n", resourceLimit.rlim_cur);
	printf("Maximum: %ld\n", resourceLimit.rlim_max);

	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P03$ gcc p3.c -o p3

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P03$ ./p3
====== Currently size of the process stack, in bytes ======
Current: 8388608
====== Updated size of the process stack, in bytes ======
Current: 10000
Maximum: 20000

*/
