/*
============================================================================
Name : 11.c
Author : Anshul Kakirde
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
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

    int fd_dup = dup(fd);
    if (fd_dup == -1) exit(EXIT_FAILURE);

    write(fd, "Original descriptor\n", 20);
    write(fd_dup, "Duplicated with dup\n", 20);

    close(fd);
    close(fd_dup);

    return 0;
}

