/*
============================================================================
Name : 24.c
Author : Anshul Kakirde
Description :Write a program to create a Zombie state of the running program.
Date: 27th Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        
        printf("I am the Child process.\n");
        while (1) {
            // ye usko chalane ke liye rakha he ki vo  terminate na ho jaye
        }
    } else {
        
        printf("I am the Parent process and do force exit to make child orphan .\n");
        exit(0);
    }

    return 0;
}


/* 
OUTPUT IS
I am the Parent process and do force exit to make child orphan .
I am the Child process.

*/
