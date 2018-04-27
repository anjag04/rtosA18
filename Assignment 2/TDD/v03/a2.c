/*
 v03 TDD: Input file is passed into program and output file is created with same contents
 Program is run using: ./a2 data.txt -pthread
*/

#include "a2.h"

/* Global Pipe For Thread Communication */
int Pipe = 0;
char writeBuf[] = "This has been through the pipe!\n";
char readBuf[MESSLENGTH];

int main (int argc, char**argv)
{	
  /* Array of two ints for file descriptors */
  int n, fd[2];

  if (checkInput (argc))
  {
    printf ("\nNo input file to read!\n");
    return 1;
  }
  
  else
  {
    Pipe = pipe (fd);
    //createPipe (fd);
    if (Pipe < 0)
    {
  /* Using perror () for the first time */
      perror ("pipe error");
      exit (1);
    }
   
    else 
    {
      readFile (argv);
      writePipe (fd);
      readPipe (n, fd);
	    writeFile ();
    }
  }

	return 0;
}