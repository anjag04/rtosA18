/* 

first pipe example from Haviland http://web.mst.edu/~ercal/284/PipeExamples/Pipe1.c

*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE  16
#define PIPE_SIZE 2
#define BUFFER_SIZE 256

/* Global Pipe variable */
int Pipe[PIPE_SIZE];

/*
char *msg1 = "This has";
char *msg2 = "been through";
char *msg3 = "the pipe!";
*/

void help ()
{
  printf ("The program should have one input parameter,\n");
  printf ("the parameter is the document to be read.\n");
  printf ("Usage: exe text_file_path\n"); 
  printf ("Example: exe txt_file_path\n");
}

void openPipe ()
{
/* open pipe */
	printf ("REACHED PIPE!\n");
  if (pipe (Pipe) == -1)
  {    
		perror ("pipe call error");
   	exit (1);
  }
  else 
	{
		printf ("REACHED OPEN FILE!\n");
	}
}

void writePipe (char writeMe)
{
	char writeToPipe[i] = writeMe[];
	
/* write down pipe */
	printf ("strLine = %s\n", writeToPipe);
  printf ("WRITING TO PIPE!\n");
	write (Pipe[1], writeToPipe, MSGSIZE);
	printf ("Pipe[1] = %s\n", Pipe[1]);
/* write (p[1], msg2, MSGSIZE);
   write (p[1], msg3, MSGSIZE);
*/
}

int main (int argc, char**argv)
{
  if (argc != 2) 
    help();
	else
  {
  	char inbuf[MSGSIZE];
		int j;
		int fd;
//    char buf[FILE_CHARS];
	openPipe ();
  
	/* read text file */
		FILE* file = fopen (argv [1], "r");
  	char strLine[BUFFER_SIZE];
    char ch;

		fgets (strLine,BUFFER_SIZE,file); //read a line from the text file.

		writePipe (strLine);

   	/* read pipe */
  /* 	for (j = 0; j < 3; j++)
   	{   
		*/	read (Pipe[1], inbuf, MSGSIZE);
    	printf ("READING FROM PIPE!\n");
			printf ("%s\n", inbuf);
   	}

  exit (0);

	return 0;
}