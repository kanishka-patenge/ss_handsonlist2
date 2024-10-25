/*
Name : p19d.c
Author: Patenge Kanishka
Description: Create a FIFO file by
    d. mknod system call    

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
    int ans = mknod("fileD", S_IFIFO, 0);

    if(ans == -1)
    {
        printf("Error in creating FIFO file using mknod() sys call!\n");
        exit(-1);
    }

    printf("FIFO file created!\n");

	return 0;
}

/*
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ gcc p19d.c -o p19d
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ ./p19d 
FIFO file created!
kanishka@kanishka-HP-Laptop-15s-fq5xxx:~/Desktop/Software-Systems/Hands-on-list-II/P19$ ls -l
total 36
prw-rw-r-- 1 kanishka kanishka     0 Sep 18 17:31 fileA
prw-rw-r-- 1 kanishka kanishka     0 Sep 18 17:34 fileB
p--------- 1 kanishka kanishka     0 Sep 18 18:01 fileD

*/
