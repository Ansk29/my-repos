/*
============================================================================
Name : 10c
Author : Anshul Kakirde
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
Date: 21th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "original.txt";
    const char *initial_data = "1234567890";  
    const char *additional_data = "ABCDEFGHIJ"; 

    
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Write 10 bytes to the file
    if (write(fd, initial_data, 10) != 10) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    // Move the file pointer by 10 bytes using lseek
    off_t new_offset = lseek(fd, 10, SEEK_SET);
    if (new_offset == (off_t)-1) {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }

    // Write another 10 bytes at the new position
    if (write(fd, additional_data, 10) != 10) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    // Close the file
    close(fd);

    printf("Data written successfully.\n");

    return EXIT_SUCCESS;
}



/* OUTPUT 
Data written successfully.

*/
