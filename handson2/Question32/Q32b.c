#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    int shm_fd = shm_open("/shared_mem", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));
    int *data = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_t *sem = sem_open("/shared_semaphore", O_CREAT, 0644, 1);

    while (1) {
        sem_wait(sem);
        (*data)++;
        printf("Shared memory value: %d\n", *data);
        sem_post(sem);
        sleep(1);
    }

    sem_close(sem);
    sem_unlink("/shared_semaphore");
    shm_unlink("/shared_mem");

    return 0;
}

