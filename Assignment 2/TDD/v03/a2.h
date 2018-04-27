/*
	Preprocessor and Prototypes for destination file functions
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
		printf ("==File Contents==:\n\n");
    for (int i = 0; i < LINES_TO_PRINT; i++)
    {
    //read one line from the text file.
			fgets (strLine,BUFFER_SIZE,file);
      printf ("%s", strLine);
    }
	}
}

/*
	Preprocessor for Pipe Function
*/
	#include <unistd.h>
	#include <string.h>
	#define MESSLENGTH 80
/*
	Pipe Function Prototypes
*/
int createPipe (int * fd)
{
//	int pipe (fd[2]);
}

void writePipe (int * fd)
{
  char writeBuf [] = "This has been through the pipe!\n";
  /* close the 'read' end of pipe */
	close (fd [0]);
  write (fd [1], writeBuf, strlen (writeBuf));
	/* close the 'write' end after writing */
	close (fd[1]);

	exit (0);
}

void readPipe (int n, int * fd)
{
  char readBuf [MESSLENGTH];
	/* ensure 'write' end of pipe is closed */
  close (fd[1]);
  n = read (fd [0], readBuf, MESSLENGTH);
  /* put null char at the end of string */
	readBuf [n] = '\0';
  printf ("%s", readBuf);
	/* close the 'write' end after writing */
	close (fd[0]);

	exit (0);
}