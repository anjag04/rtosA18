/*
Exercise 2. You are required to write a program to help you understand pipe concept. 
The program needs to use fork to separate the program into two sub-processes. 
In the parent process, the program writes a content to pipe. 
In the child process, the program reads the content from pipe and outputs it to the monitor.
A program framework is given, you need to fill the program and satisfy the requirement.
*/
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

// #include <unistd.h>

#define MESSLENGTH 80

char pourIntoPipe[] = "This has been through the pipe!\n";
char collectFromPipe[MESSLENGTH];

int main(void)
{
  int n, fd[2];
  pid_t pid;

  /* open pipe */

  if ( pipe (fd) < 0 )
    perror ("pipe error");
    

  if ( (pid = fork()) < 0 )
    perror ("fork error");
    
  else if ( pid > 0 )
  /* parent will do the writing this time */
  {
	/*write the content of purIntoPipe variable into pipe */
    // your program
    write (fd, pourIntoPipe, MESSLENGTH);
	  
	/* wait child process to finish*/
	  // your program
    wait (NULL);
	  
  }  
    
  else 
  {
  /* child will do the reading. */
	  
	/*read content from pipe*/
    // your program
    read (fd[0], collectFromPipe, MESSLENGTH);
	  
	/*print the content to the monitor*/
    printf ("%s", collectFromPipe);
  }
    
  return (0);
}