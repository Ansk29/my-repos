#include <unistd.h>
#include <stdio.h>

int main() {
    char *envp[] = {NULL}; 
    if (execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp) == -1) {
        perror("commmand fail");
    }
    return 0;
}

