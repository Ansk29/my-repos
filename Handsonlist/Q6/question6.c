/*
============================================================================
Name : 6.c
Author : Anshul Kakirde
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 20th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main() {
    char input[100];
    

    // Read input from STDIN
    printf("Enter the text you need to input  ");
    fgets(input, sizeof(input), stdin); // stdin call use kara;

    //: Write directly to STDOUT using fprintf
    fprintf(stdout, "Here is the output given is: %s\n", input);

    return 0;
}

/*
Enter the text you need to input -- hello i am anshul  aur ye ss ka project
Here is the output given: hello i am anshul  aur ye ss ka project
*/
