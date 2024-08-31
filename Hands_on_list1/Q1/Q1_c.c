#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("q1fifo", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    return 0;
}

