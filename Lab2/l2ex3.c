/*
  Exercise 3: Write program A to separate the main program into two processes.
  In the child process, it needs to calculate the sum of 1 to 10000l in the parent process it needs to calculate -10000 to -1 
  Both processes need to print out their results and exit normally
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define POS_SUM_LIMIT 10000
#define NEG_SUM_LIMIT -10000

int sumOf (int sumToValue);


int main ()
{
  pid_t fork (void);
  pid_t pid;

  switch (pid = fork())
  {
    case -1:
    perror ("fork:");
    exit (-1);

    case 0:
//  do_child_things();
    printf ("\nChild Process\n");
    printf ("sum of 0 to %d, = %d\n", POS_SUM_LIMIT, sumOf(POS_SUM_LIMIT));
    exit (0);
    break;
  
    default:
    printf("child pid = %d, parentpid = %d\n", (int) pid , (int) getpid ());
//  do_parent_things();
    printf ("\nParent Process\n");
    printf ("sum of 0 to %d, = %d\n", NEG_SUM_LIMIT, sumOf(NEG_SUM_LIMIT));
    wait (NULL);
    break;
  }

  return 0;
}

int sumOf (int sumToValue)
{
  int sumVal = sumToValue;
  int sum = 0;
  if (sumVal > 0)
  {
    for (int i = 0; i < sumVal; i++)
    {
      sum += i;
    }
  }
  else
  {
    for (int i = 0; i > sumVal; i--)
    {
      sum += i;
    }
  }
  return sum;
}
