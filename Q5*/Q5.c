
/*
============================================================================
Name : 5.c
Author : Anshul Kakirde
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/f
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[20];
    int fd, file_num = 1;

    while (1) {
        snprintf(filename, sizeof(filename), "file%d.txt", file_num);
        fd = open(filename, O_CREAT | O_RDWR, 0644);
        if (fd == -1) exit(EXIT_FAILURE);
        file_num++;
        if (file_num > 5) file_num = 1;
        sleep(1);
    }

    return 0;
}




/*
 Run the program in the background:
./Q5 &
ps aux | grep Q5
ls -l /proc/PID/fd

*/
