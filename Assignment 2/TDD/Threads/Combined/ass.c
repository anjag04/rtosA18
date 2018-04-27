/*
	Combined Main Program
	(1) Create Pipe
	(2) Create Signals/Semaphores
	(3) Create Threads
*/

#include "ass.h"
#include "ThreadA.h"

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
	/* Create Pipe */
		int fd[2];
		pipe (fd);
	
	/* Create Signal Variables */

	/* Create Threads */
		
	/* Thread A */

	/* Read Input */
		char ** argvinput = argv;
  	FILE* file = fopen (argv [1], "r");
  	char 	pipeWrite[BUFFER_SIZE];
		char	pipeRead[BUFFER_SIZE];
  	char ch;
	//if File exists, store in buffer
  	if (file != NULL) 
  	{
			//read one line from the text file.
			printf ("==Pipe INPUT==\n\n");
		//Check what is being written to pipe
			fgets (pipeWrite,BUFFER_SIZE,file);
      printf ("%s", pipeWrite);
		// write buffer contents to pipe
			write (fd [1], pipeWrite, strlen (pipeWrite));
		// close pipe input
			close (fd[1]);
		// signal Thread B
		}

		/* Thread B */
		// read buffer contents to buffer
			read (fd[0],pipeRead, BUFFER_SIZE);
		//Check what is being read from pipe
			printf ("==Pipe OUTPUT==\n\n");
			printf ("%s", pipeWrite);
			// Signal Thread C

		/* Thread C */

		char *fileWrite = pipeWrite;

		writeFile (fileWrite);

		// Signal Thread A


	}

	return 0;
}