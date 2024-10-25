/*
Name : p4.c
Author: Patenge Kanishka
Description: Write a program to measure how much time is taken to execute 100 getppid () system call. Use time stamp counter.

Date: 11 Sept 2024
*/

#include <sys/time.h>  
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

int main()
{
    int start, end, pid;
    struct timeval timestamp;
    int iter = 0;

    start = __rdtsc();
    while(iter < 100) {
        pid = getpid();
        iter++;
    }
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d ns \n",  (int) ((end - start)/2.4));

    return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P04$ gcc p4.c -o p4
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P04$ ./p4 
PID: 4240
Time taken : 19800 ns 

*/
