/*===========================================================================
Name : 8.c
Author : Anshul Kakirde
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 22th Aug, 2024.
============================================================================
*/


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


/* Output 

read.txt file's content

fgetc()  reads  the next character from stream and returns it as an unsigned
       char cast to an int, or EOF on end of file or error.

       getc() is equivalent to fgetc() except that it may be implemented as a macro
       which evaluates stream more than once.

       getchar() is equivalent to getc(stdin).

       fgets()  reads  in  at  most  one  less than size characters from stream and
       stores them into the buffer pointed to by s.  Reading stops after an EOF  or
       a newline.  If a newline is read, it is stored into the buffer.  A terminat‐
       ing null byte ('\0') is stored after the last character in the buffer.

       ungetc() pushes c back to stream, cast to unsigned char, where it is  avail‐
       able  for  subsequent  read  operations.  Pushed-back characters will be re‐
       turned in reverse order; only one pushback is guaranteed.

       Calls to the functions described here can be mixed with each other and  with
       calls  to  other  input  functions from the stdio library for the same input
       stream.*/


