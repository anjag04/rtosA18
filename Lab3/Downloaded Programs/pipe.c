/*
 * Simple pipe() demonstration. Parent writes
 * into pipe, child reads it and prints a 
 * message on completion.
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define MESSLENGTH 80

int main(void)
{
/* An array of two ints for the file descriptors. */
  int   n, fd[2];
  pid_t pid;

  if (pipe(fd) < 0)
  {
  /* Using perror() for the first time. */
		perror ("pipe error");
    exit (1);
  }

/* Just for interest, print out the fd values. */
  printf("pipe() was successful, fds are %d, %d\n", fd[0], fd[1]);

  if ((pid = fork()) < 0)
  {
    perror ("fork error");
    exit (2);
  }
    
  else if (pid > 0)
  {
  /* Parent - parent will do the writing this time */
    char pourIntoPipe[] = "This has been through the pipe!\n";
	/* we don't want the reading end at all */
    close (fd[0]);        
    write (fd[1], pourIntoPipe, strlen(pourIntoPipe));
  } 
    
  /* Child */
	else 
  {
	/* buffer space in child   */
  	char collectFromPipe[MESSLENGTH];
	/* child will do the reading. */
    close (fd[1]);        
    n = read (fd[0], collectFromPipe, MESSLENGTH);
  /* put null char at end of string */
		collectFromPipe[n] = '\0';
    printf ("%s", collectFromPipe);
  }

  exit(0);

	return 0;
}