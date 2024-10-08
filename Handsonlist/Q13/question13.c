/*
============================================================================
Name : 13.c
Author : Anshul Kakirde
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 29th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;

    
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Setting the timeout to 10 
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Waiting for data on stdin for up to 10 seconds;
    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select()");
        return EXIT_FAILURE;
    } else if (ret== 0) {
        printf("data print after the gap og 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data available on stdin.\n");
        }
    }

    return EXIT_SUCCESS;
}


/*OUTPUT (after 10sec it prints)
data print after the gap og 10 seconds.
*/
