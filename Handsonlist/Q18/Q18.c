/*
============================================================================
Name : 18.c
Author : Anshul Kakirde
Description : 18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "records.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int records[3] = {1001, 1002, 1003}; // Initial records
    if (write(fd, records, sizeof(records)) != sizeof(records)) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Initialized 3 records in file.\n");
    close(fd);
    return 0;
}

