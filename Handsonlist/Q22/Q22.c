/*
============================================================================
Name : 22.c
Author : Anshul Kakirde
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
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
    FILE *file;

    
    file = fopen("Sample.txt", "a");  //append mode mein khola kyuki add karna he text aage ;
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    
    if (pid == 0) {
        fprintf(file, "This is written by the child process.\n");
        fclose(file);
        exit(0);
    }

   
    fprintf(file, "This is written by the parent process.\n");
    fclose(file);


printf("Done Adding by bith the process");
    
   

    return 0;
}


/*output 
Done Adding by bith the process 
*/
