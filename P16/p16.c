/*
Name : p16.c
Author: Patenge Kanishka
Description:Write a program to send and receive data from parent to child vice versa. Use two way communication

Date: 19 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	
    char *childReadBuffer, *childWriteBuffer;
    char *parentReadBuffer, *parentWriteBuffer;
    
    int pipeParent[2], pipeChild[2];

    int pipeP = pipe(pipeParent);
    int pipeC = pipe(pipeChild);

    if(pipeC == -1 || pipeP == -1)
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
        close(pipeChild[0]);
        close(pipeParent[1]);
        
        int readMSG = read(pipeParent[0], &childReadBuffer, sizeof(parentWriteBuffer));
        if(readMSG == -1)
        {
            printf("Unable to read from pipe!\n");
            exit(-1);
        }
        printf("MSG from Parent: %s\n", childReadBuffer);

        // Sending msg to parent
        childWriteBuffer = "I am fine. Thank you!";
        int writeMSG = write(pipeChild[1], &childWriteBuffer, sizeof(childWriteBuffer));
        if(writeMSG == -1)
        {
            printf("Unable to write to pipe!\n");
            exit(-1);
        }

    }
    else
    {
        close(pipeParent[0]);
        close(pipeChild[1]);

        *parentWriteBuffer = "Hello from parent, How are you?"
        int writeMSG = write(pipeParent[1], &parentWriteBuffer, sizeof(parentWriteBuffer));
        if(writeMSG == -1)
        {
            printf("Unable to write in pipe!\n");
            exit(-1);
        }

        // Reading msg from child
        int readMSG = read(pipeChild[0], &parentReadBuffer, sizeof(childWriteBuffer));
        if(readMSG == -1)
        {
            printf("Unable to read from pipe!\n");
            exit(-1);
        }
        printf("MSG from child: %s\n", parentReadBuffer);

    }

	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P16$ gcc p16.c -o p16
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P16$ ./p16 
MSG from Parent: Hello from parent, How are you?
MSG from child: I am fine. Thank you!

*/
