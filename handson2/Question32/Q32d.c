#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    sem_t *sem = sem_open("/counting_semaphore", O_CREAT, 0644, 2);

    while (1) {
        sem_wait(sem);
        printf("Resource acquired\n");
        sleep(2);  
        printf("Resource released\n");
        sem_post(sem);
        sleep(1);
    }

    sem_close(sem);
    sem_unlink("/counting_semaphore");

    return 0;
}

