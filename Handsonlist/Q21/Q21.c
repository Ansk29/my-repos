/*
/*
============================================================================
Name : 21c
Author : Anshul Kakirde
Description :Write a program, call fork and print the parent and child process id.
Date: 27th Aug, 2024.
============================================================================
*/
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    pid_t pid = fork();

    
    if (pid < 0) {
        
        perror("Error in creating child");
        return 1;
    }

    if (pid == 0) {
        
        printf("We are in Child process:\n");
        printf("Child ka  PID: he%d\n", getpid());
        printf("Parent ka PID: he %d\n", getppid());
    } else {
        
        printf(" We are in Parent process:\n");
        printf("Parent ka PID: %d\n", getpid());
        printf("Child ka PID: %d\n", pid);
    }

    return 0;
}


/* OUTPUT !!!
We are in Parent process:
Parent ka PID: 44991
Child ka PID: 44992
We are in Child process:
Child ka  PID: he44992
Parent ka PID: he 44991

paren treturn karta he child ka pid usko ek variable mein leke check bhi kar skate jo return hua dono same he ;

child ka process id toh zero chiye 

*/


