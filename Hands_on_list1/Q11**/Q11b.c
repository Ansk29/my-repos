/*
============================================================================
Name : 11.c
Author : Anshul Kakirde
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) exit(EXIT_FAILURE);

    int fd_dup2 = dup2(fd, 10);
    if (fd_dup2 == -1) exit(EXIT_FAILURE);

    write(fd, "Original descriptor\n", 20);
    write(fd_dup2, "Duplicated with dup2\n", 21);

    close(fd);
    close(fd_dup2);

    return 0;
}

