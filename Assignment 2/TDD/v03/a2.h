/*
	Prototypes for destination file functions
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 256
#define LINES_TO_PRINT 14

/*
	Create and save a new file
*/

void writeFile (void)
{
// open a text file and print to screen
	int fd;
// createUniqueFileName
	time_t rawtime;
	char buffer [255];

	time (&rawtime);
	/* SAVEFILE NAME GETS CHANGED HERE */
	sprintf (buffer, "GenFile-%s.txt",ctime (&rawtime));

	fopen (buffer, "w");

	if (fd == -1)
	{
		printf ("Failed to create and open the file.\n");
    exit (1);
  }
}

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
	read file contents and store in buffer
*/
void readFile (char ** argv)
{
	char ** argvinput = argv;
  FILE* file = fopen (argv [1], "r");
  char strLine[BUFFER_SIZE];
  char ch;
	//if File exists, store in buffer
  if (file != NULL) 
  {
    for (int i = 0; i < LINES_TO_PRINT; i++)
    {
    //read one line from the text file.
			fgets (strLine,BUFFER_SIZE,file);
      printf ("%s", strLine);
    }
	}
}

/*
	Libraries for Pipe Function
*/