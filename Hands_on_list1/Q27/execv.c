#include <unistd.h>
#include <stdio.h>

int main() {
    // Argument list for execv
    char *args[] = {"ls", "-Rl", NULL};

 
        perror("commmand fail);
    }
    return 0;
}

