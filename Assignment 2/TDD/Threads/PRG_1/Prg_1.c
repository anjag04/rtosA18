/*!
 *  @addtogroup Assignment_2
 *  @{
 */

/*!
 * @file Prg_1.c
 * 
 * @brief 
*/

/*
	Library Declarations
*/

// Threads A & B
#include <stdio.h>
#include <unistd.h>

// Thread C
#include <time.h>
#include <stdlib.h>

/*
	Check file to read is specified
*/
int checkInput (int argc)
{
	int input = argc;
	if (input != 2) 
	{
  	printf ("The program should have one input parameter,\n");
  	printf ("the parameter is the document to be read.\n");
  	printf ("Usage: exe text_file_path\n"); 
  	printf ("Example: exe txt_file_path\n");
		
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
	Thread A
*/
#include <stdio.h>
#define BUFFER_SIZE 256
#include <string.h>

/*
	Thread C
*/

void writeFile (char * fileWrite)
{
// open a text file and print to screen
	int fd;
// createUniqueFileName
	time_t rawtime;
	char buffer [255];

	time (&rawtime);
	/* SAVEFILE NAME GETS CHANGED HERE */
	const char *file =  sprintf (buffer, "GenFile-%s.txt",ctime (&rawtime));

	FILE *f = fopen (buffer, "w");

	if (fd == -1)
	{
		printf ("Failed to create and open the file.\n");
    exit (1);
  }
	else
	{
		fprintf (f, fileWrite, file);
	}
}
#include <stdio.h>
#define BUFFER_SIZE 256

void readLine (char ** argv)
{
	char ** argvinput = argv;
  FILE* file = fopen (argv [1], "r");
  char lineRead[BUFFER_SIZE];
  char ch;
	//if File exists, store in buffer
  if (file != NULL) 
  {
		printf ("==Buffer Contents==:\n\n");
    //read one line from the text file.
			fgets (lineRead,BUFFER_SIZE,file);
      printf ("%s", lineRead);
	}
}

void writePipe ()
{
	
}

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

		const char *fileWrite = pipeWrite;

		writeFile (fileWrite);

		// Signal Thread A


	}

	return 0;
}

/*!
 *@}
*/