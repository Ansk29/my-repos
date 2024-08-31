
/*
============================================================================
Name : 1.c
Author : Anshul Kakirde
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 16th Aug, 2024.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (symlink("mainfile.txt", "softlink2.txt") == -1) {
        perror("symlink");
        exit(EXIT_FAILURE);
    }
    return 0;
}

