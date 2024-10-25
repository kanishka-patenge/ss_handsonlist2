/*
Name : p17c.c
Author: Patenge Kanishka
Description: Write a program to execute ls -l | wc.
                    c. use fcntl

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
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
            fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
            close(pipefd[1]);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(STDOUT_FILENO);
            fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
            close(pipefd[0]);

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P17$ gcc p17c.c -o p17c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P17$ ./p17c
      7      56     321

*/
