/*
============================================================================
Name : 3.c
Author : Anshul Kakirde
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 16th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
const char *naam = "testing.txt";

int fd = creat(naam , S_IRUSR | S_IWUSR );

if(fd<0)
{
perror("created successfully");
return 1;
}

printf(" Descriptor for ourr file %d/n" ,fd);


if(close(fd)<0)
{
perror("close");
return 1;
}

return 0;

}

/*Descriptor for ourr file 3/n */
