/*
============================================================================
Name : 30c
Author : Anshul Kakirde
Description : Write a program to run a script at a specific time using a Daemon process. 
Date: 30th Aug, 2024.
============================================================================ */

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctime>
#include <cstdlib>

void daemonize() {
    pid_t pid = fork();
    if (pid > 0) exit(0);
    setsid();
    pid = fork();
    if (pid > 0) exit(0);
    umask(0);
    chdir("/");
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--) close(x);
}

bool is_time_to_run(int hour, int minute) {
    time_t now = time(0);
    tm* local_time = localtime(&now);
    return (local_time->tm_hour == hour && local_time->tm_min == minute);
}

int main() {
    daemonize();

    int hour = 14;
    int minute = 30;

    while (true) {
        if (is_time_to_run(hour, minute)) {
            system("/path.sh");
            sleep(60);
        }
        sleep(1);
    }

    return 0;
}

