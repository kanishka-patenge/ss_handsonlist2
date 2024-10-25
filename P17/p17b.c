/*
Name : p17b.c
Author: Patenge Kanishka
Description: Write a program to execute ls -l | wc.
                    b. use dup2

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
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[1]);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(STDOUT_FILENO);
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[0]);

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
	return 0;
}

/*

jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P17$ gcc p17b.c -o p17b
jaimin@Ubuntu-VM:~/Desktop/Software-Systems/Hands-on-list-II/P17$ ./p17b
      5      38     217

*/