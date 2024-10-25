/*
Name : p17a.c
Author: Patenge Kanishka
Description: Write a program to execute ls -l | wc.
                    a. use dup

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	
    int pipefd[2]; 
    int childPID;

    int pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the pipe!]\n");
    else
    {
        childPID = fork();

        if (childPID == -1)
            perror("Error creating child!\n");
        else if (childPID == 0)
        {
            close(STDIN_FILENO);
            dup(pipefd[0]);
            close(pipefd[1]);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(STDOUT_FILENO);
            dup(pipefd[1]);
            close(pipefd[0]);

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P17$ gcc p17a.c -o p17a
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P17$ ./p17a 
      3      20     113

*/
