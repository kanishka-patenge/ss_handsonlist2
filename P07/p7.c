/*
Name : p7.c
Author: Patenge Kanishka
Description: Write a simple program to print the created thread ids.

Date: 12 Sept 2024
*/

#include<stdio.h>
#include<pthread.h>

void *myFunc(void *str)
{
	printf("%s created!\n", (char *)str);
	
	printf("Thread ID: %ld\n", pthread_self());
}

int main()
{
	pthread_t t;
	void *r;
	
	// creating thread
	int s = pthread_create(&t, NULL, (void *)myFunc, "Thread 1") ;
	if(s != 0)
	{
		printf("Error in creating thread!\n");
	}
	pthread_join(t, &r);
	return 0;
}

/*
Output:

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P07$ gcc -pthread p7.c -o p7

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P07$ ./p7
Thread 1 created!
Thread ID: 139974593873664

*/
