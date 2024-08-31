
/*
============================================================================
Name : 4.c
Author : Anshul Kakirde
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also
Date: 16th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

	
	FILE* ptr;

	// to open
       ptr = fopen("test.txt", "a+");  //

	// to  write 
	fprintf(ptr, "%s %s %s", "Writing", "into",
			"file"); //a+ diya he append akrne ke permissions ke liye ;
			

	// O_EXCL flag help to exclusive create already exisiting hogi toh eroor de degi
	fclose(ptr);

	return 0;
}


/*Output
in test.txt
Writing into fileWriting into file
*/
