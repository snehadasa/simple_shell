#include <unistd.h>
#include <stdio.h>

int my_pid()
{
   printf("My process ID : %d\n", getpid());
   printf("My parent's ID: %d\n", getppid());

   return 0;
}
