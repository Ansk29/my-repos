
/*
=====================================================================================================
Name : 7.c
Author : Anshul Kakirde
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also
Date: 21th Aug, 2024.
======================================================================================================
*/


#include <stdio.h>


// file and the name of the copy, e.g. copy_file file.txt copy.txt#include <stdio.h>

// program should be provided with two command line arguments, the name of the 
#include <stdio.h>

// program should be provided with two command line arguments, the name of the 
// file and the name of the copy, e.g. copy_file file.txt copy.txt
int main()
{
  FILE *original, *copy;
 
  
  // orignal file read mode mein and copy wala write mein open
  original = fopen("original", "r");
  copy = fopen("copy", "w");
  
  // koi agar mile ni toh error return karo base case;
  if (original == NULL || copy == NULL)
  {
    printf("Error in opening file please check .\n");
    return 1;
  }
  
  // copy the content from the file to the copy one character at a time
  char c;// ek ek kar k e copy kar re;
  while ( (c = fgetc(original)) != EOF )
    fputc(c, copy);
  
  // close the files when we are done with them
  fclose(original);
  fclose(copy);

  return 0;
}

/*
output is copied in the new file 
*/
