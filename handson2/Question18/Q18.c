
/*
============================================================================
Name : 18.c
Author : Anshul Kakirde
Description: . Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd1[2], pipefd2[2];
    pipe(pipefd1);
    pipe(pipefd2);

    if (fork() == 0) {
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[0]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    
    close(pipefd1[1]);

    if (fork() == 0) {
        dup2(pipefd1[0], STDIN_FILENO);
        dup2(pipefd2[1], STDOUT_FILENO);
        close(pipefd2[0]);
        execlp("grep", "grep", "^d", NULL);
        exit(1);
    }

    close(pipefd1[0]);
    close(pipefd2[1]);

    if (fork() == 0) {
        dup2(pipefd2[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
        exit(1);
    }

    close(pipefd2[0]);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*0
*/

