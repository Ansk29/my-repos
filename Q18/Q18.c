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
#include <sys/file.h>

#define FILE_NAME "records.txt"
#define NUM_RECORDS 3
#define RECORD_SIZE 100

int main() {
    int fd;
    char buffer[RECORD_SIZE];
    int record_number;

   
    fd = open(FILE_NAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_RECORDS; i++) {
        sprintf(buffer, "Record %d", i + 1);
        write(fd, buffer, RECORD_SIZE);
    }

    
    printf("Enter record number (1-%d): ", NUM_RECORDS);
    scanf("%d", &record_number);

   
    if (fcntl(fd, F_SETLKW, &flock(record_number - 1, F_WRLCK, 0)) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

   
    lseek(fd, (record_number - 1) * RECORD_SIZE, SEEK_SET);
    read(fd, buffer, RECORD_SIZE);
    printf("Original record: %s\n", buffer);

    
    strcat(buffer, " (Modified)");
    write(fd, buffer, RECORD_SIZE);
    printf("Modified record: %s\n", buffer);


    if (fcntl(fd, F_SETLKW, &flock(record_number - 1, F_UNLCK, 0)) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

   
    close(fd);

    return 0;
}
