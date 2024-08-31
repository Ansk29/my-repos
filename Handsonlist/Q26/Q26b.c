/*
============================================================================
Name : 26.c
Author : Anshul Kakirde
Description : 26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

============================================================================
*/
#include <cstdlib>

int main() {
    system("./program_a Anshul");
    return 0;
}

