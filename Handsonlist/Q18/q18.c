#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void lock_record(int fd, int record_num, short lock_type) {
    struct flock lock;
    lock.l_type = lock_type;        
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * sizeof(int); /
    lock.l_len = sizeof(int);       

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire lock");
        exit(EXIT_FAILURE);
    }
}

void unlock_record(int fd, int record_num) {
    struct flock lock;
    lock.l_type = F_UNLCK;          
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * sizeof(int);
    lock.l_len = sizeof(int);

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *filename = "records.txt";
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int record_num = 2;  

    
    lock_record(fd, record_num, F_RDLCK);

    
    int record_value;
    lseek(fd, record_num * sizeof(int), SEEK_SET);
    if (read(fd, &record_value, sizeof(record_value)) != sizeof(record_value)) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Value of record %d: %d\n", record_num + 1, record_value);

    
    unlock_record(fd, record_num);

    close(fd);
    return 0;
}

