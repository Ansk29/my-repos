/*
============================================================================
Name : 29.c
Author : Anshul Kakirde
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 29th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    struct sched_param param;  // required structure ;
    int policy;

    
    policy = sched_getscheduler(0); // 0 bata raha current process ko lena  he;
    
    if (policy == -1) {
        perror("error");
        exit(EXIT_FAILURE);
    }

    
    printf("Current policy: %s\n",
           policy == SCHED_FIFO ? "FIFO" :  // check kara dono mein se konsi he apni current wali
           policy == SCHED_RR ? "RR" :
           "OTHER");

   
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);  // syntax chck in book
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

  
    printf("New policy: SCHED_FIFO\n");

    return 0;
}

/*
Current policy: OTHER
sched_setscheduler: Operation not permitted
error whhy kyuki root use hi kar sakta he ;


Current policy: OTHER
New policy: SCHED_FIFO

sudo used then operation done;

*/

