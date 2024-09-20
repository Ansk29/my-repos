/*
============================================================================
Name : 32.c
Author : Anshul Kakirde
Description: 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date:  20 sept 2024.
============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    sem_t *sem = sem_open("/ticket_semaphore", O_CREAT, 0644, 1);
    int ticket = 0;

    while(1) {
        sem_wait(sem);
        ticket++;
        printf("Ticket number: %d\n", ticket);
        sem_post(sem);
        sleep(1);
    }

    sem_close(sem);
    sem_unlink("/ticket_semaphore");

    return 0;
}

