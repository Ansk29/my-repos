#include <unistd.h>
#include <stdio.h>

int main() {
   
    if (execl("/bin/ls", "ls", "-Rl", (char *)NULL) == -1) {
        perror("commmand fail");
    }
    return 0;
}

