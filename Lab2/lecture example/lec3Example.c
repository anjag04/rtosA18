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
