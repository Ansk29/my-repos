

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Banao file pointer and open the file 
    // read mode.
    FILE* file = fopen("read.txt", "r");

    
    char line[256];

   
    if (file != NULL) {
       // read the characters line by line USING FGETS
        while (fgets(line, sizeof(line), file)) {
          
            printf("%s", line);
        }

        
        fclose(file);
    }
    else {
        // Print an error message to the standard error
        // stream if the file cannot be opened.
        fprintf(stderr, "errro cant open file \n");
    }

    return 0;
}
