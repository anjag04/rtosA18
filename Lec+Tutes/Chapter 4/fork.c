/*
pid t pid;
pid = fork();
if (pid == 0) 
{ 
/* child process */
//  fork ();
  thread create( . . .);
}
fork ();
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
  printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), fork());
  return 0;
}
