/*
Name : p18.c
Author: Patenge Kanishka
Description: Write a program to find out total number of directories on the pwd.
                        execute ls -l | grep ^d | wc ? Use only dup2.

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{	
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2];
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);

    if (pipeOneStatus == -1 || pipeTwoStatus)
        perror("Error while creating the pipe!\n");
    else
    {
        childOne = fork();

        if (childOne == -1)
            perror("Error while creating first child!\n");
        else if (childOne == 0)
        {
            close(pipeCmdTwoToThree[1]);
            close(pipeCmdOneToTwo[0]);
            close(pipeCmdOneToTwo[1]);

            close(STDIN_FILENO);
            dup2(pipeCmdTwoToThree[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            childTwo = fork();

            if (childTwo == -1)
                perror("Error while creating second child!\n");
            else if (childTwo == 0)
            {
                close(pipeCmdOneToTwo[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDIN_FILENO);
                dup2(pipeCmdOneToTwo[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else
            {
                close(pipeCmdOneToTwo[0]);
                close(pipeCmdTwoToThree[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDOUT_FILENO);
                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO);

                execl("/usr/bin/ls", "ls -l", "-l", NULL);
            }
        }
    }
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ gcc p18.c -o p18
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ ./p18 
      0       0       0
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ ls -l
total 24
-rwxrwxr-x 1 kanishka kanishka 16960 Sep 19 16:34 p18
-rw-rw-r-- 1 kanishka kanishka  2182 Sep 19 16:34 p18.c
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ mkdir temp
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ ./p18 
      1       9      51
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ ls -l
total 28
-rwxrwxr-x 1 kanishka kanishka 16960 Sep 19 16:34 p18
-rw-rw-r-- 1 kanishka kanishka  2182 Sep 19 16:34 p18.c
drwxrwxr-x 2 kanishka kanishka  4096 Sep 19 16:34 temp
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P18$ ls -l | grep ^d | wc
      1       9      51

*/
