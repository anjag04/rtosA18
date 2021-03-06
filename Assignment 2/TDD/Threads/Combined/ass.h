/*
	ass.h
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
#define fileNameBuf_SIZE 256
#include <string.h>

/*
	Thread C
*/

void writeFile (char * fileWrite)
{
// open a text file and print to screen
	int fd;d
// createUniqueFileName
	time_t rawtime;
	char fileNameBuf [255];

	time (&rawtime);
	/* SAVEFILE NAME GETS CHANGED HERE */
	int file = sprintf (fileNameBuf, "GenFile-%s.txt",ctime (&rawtime));

	FILE *f = fopen (fileNameBuf, "w");

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