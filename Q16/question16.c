#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void lock_file(int fd, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *filename = "testfile.txt";
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    
    lock_file(fd, F_WRLCK);
    printf("Write lock acquired.\n");

    
    unlock_file(fd);
    printf("Write lock released.\n");

    close(fd);
    return EXIT_SUCCESS;
}

/*OUTPUT is
Write lock acquired.
Write lock released.
*/
