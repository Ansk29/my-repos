/*
============================================================================
Name : 25.c
Author : Anshul Kakirde
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2024.
============================================================================
*/






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid1 == 0) {
        printf("Child process 1 (PID: %d) is running.\n", getpid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid2 == 0) {
        printf("Child process 2 (PID: %d) is running.\n", getpid());
        exit(0);
    }

    pid3 = fork();
    if (pid3 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid3 == 0) {
        printf("Child process 3 (PID: %d) is running.\n", getpid());
        exit(0);
    }

    //  we will wait for child process 2
    printf("Parent process (PID: %d) is waiting for child process 2.\n", getpid());
    waitpid(pid2, &status, 0);
    printf("Parent process has collected the exit status of child process 2.\n");

    

    return 0;
}


/*  !! OUTPUT IS - !!
Child process 1 (PID: 46720) is running.
Child process 2 (PID: 46721) is running.
Parent process (PID: 46719) is waiting for child process 2.
Child process 3 (PID: 46722) is running.
Parent process has collected the exit status of child process 2.

*/
