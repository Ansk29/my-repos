#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        
        printf("Child process has the id (PID: %d) and is exiting\n", getpid());
        exit(0); 
    } else {
        
        printf("I am the parent process with the id (PID: %d) will wait before calling wait().\n", getpid());

        // Sleep kara diya tai child jab tak execute ho jaye;
        sleep(10);

        // child kahatm hone ke baad bhi parent ne uska status nahi manga tab tak ke liye vo zombie ho jjyega;
        int status;
        waitpid(pid, &status, 0);
        printf("Parent process (PID: %d) now collected the status of the child.\n", getpid());
    }

    return 0;
}





/* I am the parent process with the id (PID: 45966) will wait before calling wait().
Child process has the id (PID: 45967) and is exiting


10 sec wait karne ke baad ye wala aayega aur us time tak ke liye process zombie tha jab tak 
Parent process (PID: 45966) now collected the  status of the child.*/
