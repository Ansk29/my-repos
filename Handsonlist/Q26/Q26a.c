#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    char *program = "./a.out";
    char *arg1 = "world ";  // 

    // Using execlp to 

    if (execlp(program, program, arg1, NULL) == -1) {
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }

    // This line won't be reached unless execlp fails
    printf("This line will not be printed if execlp is successful\n");

    return 0;
}

