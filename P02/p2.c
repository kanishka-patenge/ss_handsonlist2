/*
Name : p2.c
Author: Patenge Kanishka
Description: Write a program to print the system resource limits. Use getrlimit system call.

Date: 11 Sept 2024
*/

#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>

int main()
{
	struct rlimit rlim;

	int resourcesName[] = {RLIMIT_AS, RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE, RLIMIT_LOCKS, RLIMIT_MEMLOCK, RLIMIT_MSGQUEUE, RLIMIT_RTPRIO, RLIMIT_STACK};
	char *details[] = {"Maximum size of the process's virtual memory (address space): ", "Maximum size of a core file: ", "Limit, in seconds, on the amount of CPU time that the process can consume: ", "Maximum size of the process's data segment: ", "Maximum size in bytes of files that the process may create: " , "Limit on the combined number of flock locks and  fcntl: ", "Maximum  number of bytes of memory that may be locked into RAM: ", "Limit on the number of bytes that can be allocated for message queues: ", "Specifies a ceiling on the real-time priority: ","Maximum size of the process stack, in bytes: "};

	int arrSize = sizeof(resourcesName)/sizeof(resourcesName[0]);

	for(int	i = 0; i < arrSize; i++)
	{
		printf("%s", details[i]);

		// Getting resource limit
		int l = getrlimit(resourcesName[i], &rlim);

		if(l == -1)
		{
			printf("-1\n");
		}

		else if(rlim.rlim_cur == RLIM_INFINITY)
		{
			printf("Infinite\n");
		}

		else
		{
			printf("%ld\n", rlim.rlim_cur);
		}
	}
	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P02$ gcc p2.c -o p2
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P02$ ./p2 
Maximum size of the process's virtual memory (address space): Infinite
Maximum size of a core file: 0
Limit, in seconds, on the amount of CPU time that the process can consume: Infinite
Maximum size of the process's data segment: Infinite
Maximum size in bytes of files that the process may create: Infinite
Limit on the combined number of flock locks and  fcntl: Infinite
Maximum  number of bytes of memory that may be locked into RAM: 996741120
Limit on the number of bytes that can be allocated for message queues: 819200
Specifies a ceiling on the real-time priority: 0
Maximum size of the process stack, in bytes: 8388608

*/
