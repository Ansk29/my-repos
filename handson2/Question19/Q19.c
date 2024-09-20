
/*
============================================================================
Name : 19.c
Author : Anshul Kakirde
Description: 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 19sept, 2024.
============================================================================
*/

/*mknod myfifo p
mkfifo myfifo

strace mknod myfifo p
strace mkfifo myfifo

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    if (mknod("myfifo", S_IFIFO | 0666, 0) < 0) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }
    printf("FIFO file created with mknod.\n");
    return 0;
}


*/

/*FIFO file created using mknod
mkfifo: File exists*/

