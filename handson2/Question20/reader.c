
/*
============================================================================
Name : 20.c
Author : Anshul Kakirde
Description: 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "/home/anshul-kakirde/Handsonlist 2/Solutions/Q20/myfifo";
    int fd;
    char buffer[100];

    fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Message received: %s\n", buffer);
    close(fd);

    return 0;
}


/*
gcc -o writer writer.c
gcc -o reader reader.c
*/
