#include <sched.h>
#include <stdio.h>

int main() {
    int max, min;

    
    max= sched_get_priority_max(SCHED_FIFO);
    if (max== -1) {
        perror("error");
        return 1;
    }

    
    min = sched_get_priority_min(SCHED_FIFO);
    if (min == -1) {
        perror("error");
        return 1;
    }

    
    printf("Maximum  priority for SCHED_FIFO: %d\n", max);
    printf("Minimum Priority for SCHED_FIFO: %d\n", min);

    return 0;
}

/* 


OUTPUT -
Maximum  priority for SCHED_FIFO: 99
Minimum Priority for SCHED_FIFO: 1

*/
