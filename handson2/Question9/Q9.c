/*
============================================================================
Name : 9.c
Author : Anshul Kakirde
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: , 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGINT received but should be ignored.\n");
}

int main(void) {
    
    signal(SIGINT, SIG_IGN);

    
    printf("SIGINT is now ignored. Press Ctrl+C to test.\n");
    pause();


    signal(SIGINT, SIG_DFL);

    printf("SIGINT action reset to default.\n");


    pause();

    return 0;
}


/*SIGINT is now ignored. Press Ctrl+C to test. */
