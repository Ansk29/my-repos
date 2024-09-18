/*
============================================================================
Name : 2.c
Author : Anshul Kakirde
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 16th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("ininity /t");
        sleep(1); 
    }
    return 0;
}


/* 
##(./infinite &) to run in the background

## ls /proc


cd /proc/7227 

cat status

cat stat

we could also do this with fork and then find out the child ki pid and then use background mein run  kar sakte hproc se 
*/
