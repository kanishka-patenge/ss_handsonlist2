/*
Name : p15.c
Author: Patenge Kanishka
Program Description: Write a simple program to send some data from parent to the child process.

Date: 18 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	
    char *parentMSG = "Hello from parent, How are you?", *msgFromParent;
    int writeMSG, readMSG;

    int pipeCom[2];
    int pipeCreate = pipe(pipeCom);

    if(pipeCreate == -1)
    {
        printf("Unable to create pipe!\n");
        exit(-1);
    }

    int child = fork();
    if(child == -1)
    {
        printf("Error in creating child process!\n");
        exit(-1);
    }
    else if(child == 0)
    {
        readMSG = read(pipeCom[0], &msgFromParent, sizeof(parentMSG));
        if(readMSG == -1)
        {
            printf("Unable to read from pipe!\n");
            exit(-1);
        }
        printf("MSG from Parent: %s\n", msgFromParent);
    }
    else
    {
        writeMSG = write(pipeCom[1], &parentMSG, sizeof(parentMSG));
        if(writeMSG == -1)
        {
            printf("Unable to write in pipe!\n");
            exit(-1);
        }
    }

	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P15$ gcc p15.c -o p15
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P15$ ./p15 
MSG from Parent: Hello from parent, How are you?

*/
