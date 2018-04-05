/*
 * The fork() system call is used to create another process. The child
 * will print "Hello " and the parent will print "World\n". Often the 
 * child will execute before the parent and the expected string will 
 * appear on stdout. Every now and again though, the race condition will
 * be exposed, and the two strings will be printed in the wrong order.
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	pid_t childpid;

	switch (childpid = fork ())
    {
      case -1: printf ("Problem with fork(), terminating!\n");
	      exit (1);
	    break; /* redundant */ 
	  case 0:  /* Child process */
	  {
	      printf ("Hello ");
	  }
	    break;
	  
	  default: /* Parent process */
	  {
	      printf ("World\n");
	  }
	    break;
    }
    
    exit (0);
}

