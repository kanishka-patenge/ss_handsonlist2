/*
Name : p19e.c
Author: Patenge Kanishka
Description: Create a FIFO file by
        e. mkfifo library function    

Date: 18 Sept 2024
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{		
    int ans = mkfifo("fileE", S_IRWXU);

    if(ans == -1)
    {
        printf("Error in creating FIFO file using mkfifo library!\n");
        exit(-1);
    }

    printf("FIFO file created!\n");

	return 0;
}

/*

kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ gcc p19e.c -o p19e
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ ./p19e
FIFO file created!
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ ls -l
total 60
prw-rw-r-- 1 kanishka kanishka     0 Sep 18 17:31 fileA
prw-rw-r-- 1 kanishka kanishka     0 Sep 18 17:34 fileB
p--------- 1 kanishka kanishka     0 Sep 18 18:01 fileD
prwx------ 1 kanishka kanishka     0 Sep 18 18:08 fileE

*/
