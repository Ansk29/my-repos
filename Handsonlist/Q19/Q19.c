#include <unistd.h> // ye header use kara he ;
#include <stdio.h>
#include <stdint.h>

// time taken to execute get pid system call;
//time stamp counter ;

static inline uint64_t read_tsc() {  // not understood dhang se 
    uint32_t lo, hi;
    // Inline assembly to read the TSC
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main()
{
uint64_t startingtime =read_tsc(); // ye data type he uska ; 

pid_t pid =getpid();

uint64_t endingtime =read_tsc();

uint64_t totaltime = endingtime -startingtime;

printf("process id return by the system call is %d  " ,pid);
printf("total time taken is %llu\n " ,(unsigned long long) totaltime);
printf("/n unit he cpu cucle aur run hoti he 2.4Hz pe");

return 0;
}


/* 

!!!OUTPUT IS !!!!!

process id return by the system call is 43361  total time taken is 20349
 /n unit he cpu cucle aur run hoti he 2.4Hz pe
 
 
 Times() system call se bhi ek process ko total kitna time laga ye hum nikal sakte he;
 PAGE NO 316 Book
 
 clock_t tms_utime ;
 
*/
