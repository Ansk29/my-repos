#include <unistd.h>
#include <stdio.h>

int main() {
    
    char *args[] = {"ls", "-Rl", NULL};

   
    // The command name `ls` will be searched in the directories listed in PATH,
    // so no need to specify the directory.
    if (execvp("ls", args) == -1) {
        perror("commmand fail");
    }
    return 0;
}

