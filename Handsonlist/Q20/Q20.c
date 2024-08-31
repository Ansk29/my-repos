/* /*
============================================================================
Name : 20.c
Author : Anshul Kakirde
Description :Find out the priority of your running program. Modify the priority with nice command
Date: 27th Aug, 2024.
============================================================================
*/
*/
#include <sys/time.h>
#include <sys/resource.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>


int main(){

int pid = 2002;
int ret;
ret = getpriority (PRIO_PROCESS, pid);
if (ret == -1)
perror ("cant find");

printf ("nice value is %d\n", ret);

return 0;}


/*
for this particular process example 2002 
OUTPUT:- nice value is 0;
*/



/*part b*/
int main()
{

int pid =2002; // proc command se nikala
ret = setpriority (PRIO_PGRP, pid, 10);
if (ret == -1)
perror ("setpriority");

printf("priority was changed");

return 0;}




/* Book page no 191 Nice command to get and set priority */
Output Priority was cahnged
*/
