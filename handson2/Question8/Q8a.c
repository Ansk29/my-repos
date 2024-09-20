/*
============================================================================
Name : 8.c
Author : Anshul Kakirde
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 16sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    if (signum == SIGSEGV) {
        printf("Caught SIGSEGV\n");
        exit(1);
    }
}

int main(void) {
    signal(SIGSEGV, signal_handler);

    // Deliberately cause a segmentation fault
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}

