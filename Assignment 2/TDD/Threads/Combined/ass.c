/*
	Combined Main Program
	(1) Create Pipe
	(2) Create Signals/Semaphores
	(3) Create Threads
*/

#include "ass.h"
#include "ThreadA.h"
#include "Initialise.h"

int main (int argc, char**argv)
{
	/* Check for input text file */
	if (checkInput (argc))
  {
    printf ("\nNo input file to read!\n");
    return 1;
  }

	else
	{

	/* An array of two ints for the file descriptors. */
  int   n, myPipeFD[2];
  pid_t pid;
  
	/* Create Pipe and Fork*/
  createPipeFork (myPipeFD, pid);

	
	/* Create Signal Variables */

	/* Create Threads */

		
	/* Thread A */

	/* Read Input */
		char ** argvinput = argv;
  	FILE* file = fopen (argv [1], "r");
  	char 	pipeWrite[BUFFER_SIZE];
		char	pipeRead[BUFFER_SIZE];
  	char ch;
		// if File exists, store in buffer
  	if (file != NULL) 
  	{
		// read one line from the text file.
			fgets (pipeWrite,BUFFER_SIZE,file);
		// Check what is being written to pipe
      printf ("pipeWrite: %s\n", pipeWrite);
		// write buffer contents to pipe
			write (myPipeFD [1], pipeWrite, strlen (pipeWrite));
		// close pipe input
			close (myPipeFD[1]);
		// signal Thread B
		}

		/* Thread B */
		// read buffer contents to buffer
			read (myPipeFD[0], pipeRead, BUFFER_SIZE);
		
		//Check what is being read from pipe
			printf ("pipeRead: %s\n", pipeRead);
			// Signal Thread C

		/* Thread C */

		char *fileWrite = pipeWrite;

		writeFile (fileWrite);

		// Signal Thread A


	}

	return 0;
}