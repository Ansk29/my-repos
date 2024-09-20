
/*
============================================================================
Name : 10.c
Author : Anshul Kakirde
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 18sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void ignore_sigint(int sig) {
    printf("SIGINT ignored!\n");
}

int main() {
    struct sigaction sa_ignore;
    memset(&sa_ignore, 0, sizeof(sa_ignore));
    sa_ignore.sa_handler = ignore_sigint;
    sigemptyset(&sa_ignore.sa_mask);

    if (sigaction(SIGINT, &sa_ignore, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("SIGINT ignored. Press Ctrl+C to try.\n");
    sleep(10);

    printf("Exiting program.\n");
    return 0;
}

/*SIGINT ignored. Press Ctrl+C to try.
^CSIGINT ignored!
Exiting program.*/
