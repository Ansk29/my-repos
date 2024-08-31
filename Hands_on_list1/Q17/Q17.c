/*
============================================================================
Name : 17.c
Author : Anshul Kakirde
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    FILE *file;
    int ticket_number;
    char buffer[10];

    fd = open("ticket_number", O_RDWR);
    if (fd == -1) {
        perror("Unable to open file");
        return 1;
    }

    if (lockf(fd, F_LOCK, 0) == -1) {
        perror("Unable to lock file");
        close(fd);
        return 1;
    }

    file = fdopen(fd, "r+");
    if (file == NULL) {
        perror("Unable to open file stream");
        close(fd);
        return 1;
    }

    fgets(buffer, sizeof(buffer), file);
    ticket_number = atoi(buffer);
    ticket_number += 1;

    rewind(file);
    fprintf(file, "%d", ticket_number);
    fflush(file);

    printf("Reserved ticket number: %d\n", ticket_number);

    if (lockf(fd, F_ULOCK, 0) == -1) {
        perror("Unable to unlock file");
    }

    fclose(file);
    return 0;
}


/*Reserved ticket number: 1.*/

