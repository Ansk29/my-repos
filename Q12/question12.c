#include <fcntl.h> // ye wali include kari
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main() {
    

    const char *filename ;
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("error");
        return EXIT_FAILURE;
    }

    // Getting the file staus flags
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return EXIT_FAILURE;
    }

    
    printf("File access mode for :\n");
    if (flags & O_RDONLY) {
        printf("  Readonly\n");
    }
    if (flags & O_WRONLY) {
        printf("  Writeonly");
    }
    if (flags & O_RDWR) {
        printf("  Read&Write\n");
    }

    

    // Close the file descriptor
    close(fd);

    return EXIT_SUCCESS;
}


/*OUTPUT

File access mode for :
  Read&Write
  
*/

