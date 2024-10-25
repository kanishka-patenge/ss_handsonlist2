/*
Name : p13b.c
Author: Patenge Kanishka
Description: 

Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
Find out whether the first program is able to catch the signal or not

Date: 17 Sept 2024
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{		

    int pid;
    printf("Enter PID of process: ");
    scanf("%d", &pid);

    int ans = kill(pid, SIGSTOP);
    if(ans == -1)
    {
        printf("Unable to send SIGNAL to given PID\n");
        exit(-1);
    }
	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ gcc p13a.c -o p13a
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ ./p13a &
[1] 6598
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ Hello from program 1 and PID: 6598

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ gcc p13b.c -o p13b
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ ./p13b
Enter PID of process: 6598

[1]+  Stopped                 ./p13a
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P13$ cat /proc/6598/status
Name:	p13a
Umask:	0002
State:	T (stopped)
Tgid:	6598
Ngid:	0
Pid:	6598
PPid:	6401
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 120 132 133 1000 
NStgid:	6598
NSpid:	6598
NSpgid:	6598
NSsid:	6401


*/
