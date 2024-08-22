#include <stdio.h>

int main() {
    char input[100];
    

    // Read input from STDIN
    printf("Enter the text you need to input  ");
    fgets(input, sizeof(input), stdin); // stdin call use kara;

    //: Write directly to STDOUT using fprintf
    fprintf(stdout, "Here is the output given by us: %s\n", input);

    return 0;
}
