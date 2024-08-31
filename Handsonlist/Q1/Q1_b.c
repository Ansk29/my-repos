/*
============================================================================
Name : 1.c
Author : Anshul Kakirde
Description : 1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 16th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (link("softlink2.txt", "hardlink.txt") == -1) {
        perror("link");
        exit(EXIT_FAILURE);
    }
    return 0;
}

