/*
 v03 TDD: Input file is passed into program and output file is created with same contents
 Program is run using: ./a2 data.txt -pthread
*/

#include "a2.h"

#define MESSLENGTH 80

char pourIntoPipe[] = "This has been through the pipe!\n";
char collectFromPipe[MESSLENGTH];

int forkedPipe (void)
{
  int n, fd[2];
  pid_t pid;

  printf ("Reached forkedPipe");

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
    
  return 0;
}

int main (int argc, char**argv)
{	
  forkedPipe ();
/*	if (forkedPipe() != 0)
  {
    printf ("\nPipe or Fork Error!\n");
    return 1;
  }
  else*/ if (checkInput (argc))
  {
    printf ("\nNo input file to read!\n");
    return 1;
  }
  
  else
  {
    readFile (argv);
	  writeFile ();
  }
	return 0;
}