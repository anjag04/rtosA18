#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* A trivial program that demonstrates the alarm() system call. */

#define COUNT 10

int main (void)
{
    int count = COUNT;

    if (alarm (COUNT) != 0)
    {
      printf ("There is already an alarm set ... terminating!\n");
	  exit (1);
    }

    while (1)
    {
	  printf ("Countdown to alarm signal: %d\n", count--);
	  sleep (1);
    }

    return 0;
}