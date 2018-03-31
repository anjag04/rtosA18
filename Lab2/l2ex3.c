/*
  Exercise 3: Write program A to separate the main program into two processes.
  In the child process, it needs to calculate the sum of 1 to 10000l in the parent process it needs to calculate -10000 to -1 
  Both processes need to print out their results and exit normally
*/
#include <stdio.h>

int main ()
{
  
  int 
  int sum = 0;

  for (int i = 0; i < 10000; i++)
  {
    sum += i;
  }
  //printf ("sum = %d\n", sum);

  return sum;
}

/*
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void)
pid_t pid;
switch(pid = fork())
{
  case -1:
  perror ("fork:");
  exit (-1);

  case 0:
/*  do_child_things(); */
  break;
  
  default:
  printf("child pid = %d, parent’s=%d\n”, (int) pid , (int) getpid ());
  
/*  do_parent_things(); */
  break;
}
*/
