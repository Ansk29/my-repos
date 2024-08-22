#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


int main() {
    const char *file_path = "/home/anshul-kakirde/handson1/question7"; 
    struct stat file_stat;
     if (stat(file_path, &file_stat) == -1) {
        perror("eroor in opening file");
        exit(EXIT_FAILURE);
    }
    
    // different commands for all the propwrties     
    printf("File: %s\n", file_path);
    printf("Inode: %ld\n", (long)file_stat.st_ino);
    printf("Number of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("UID: %u\n", file_stat.st_uid);
    printf("GID: %u\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", (long)file_stat.st_size);
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("Number of blocks: %ld\n", (long)file_stat.st_blocks);
    printf("Time of last access: %s", ctime(&file_stat.st_atime));
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last change: %s", ctime(&file_stat.st_ctime));

  

    return 0;
}

