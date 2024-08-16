
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

## $ ps aux | grep infinite

cd /proc/7227 

cat status

cat stat


*/
