/* 

first pipe example from Haviland http://web.mst.edu/~ercal/284/PipeExamples/Pipe1.c

*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE  16
#define PIPE_SIZE 2
#define BUFFER_SIZE 256

char *msg1 = "This has";
char *msg2 = "been through";
char *msg3 = "the pipe!";

void help ()
{
  printf ("The program should have one input parameter,\n");
  printf ("the parameter is the document to be read.\n");
  printf ("Usage: exe text_file_path\n"); 
  printf ("Example: exe txt_file_path\n");
}

int main (int argc, char**argv)
{
  if (argc != 2) 
    help();
	else
  {
  	char inbuf[MSGSIZE];
  	int p[PIPE_SIZE], j;
		int fd;
//    char buf[FILE_CHARS];

   /* open pipe */
printf ("REACHED PIPE!\n");
  	if (pipe (p) == -1)
  	{    
			perror ("pipe call error");
     	exit (1);
   	}
  else {
		printf ("REACHED OPEN FILE!\n");
  /* read text file */
		FILE* file = fopen (argv [1], "r");
  	char strLine[BUFFER_SIZE];
    char ch;

		fgets (strLine,BUFFER_SIZE,file); //read a line from the text file.
      
   /* write down pipe */
	 	printf ("strLine = %s\n", strLine);
   	printf ("WRITING TO PIPE!\n");
		write (p[1], strLine, MSGSIZE);
		printf ("p[1] = %s\n", p[1]);
/*   	write (p[1], msg2, MSGSIZE);
   	write (p[1], msg3, MSGSIZE);
*/
   	/* read pipe */
  /* 	for (j = 0; j < 3; j++)
   	{   
		*/	read (p[1], inbuf, MSGSIZE);
    	printf ("READING FROM PIPE!\n");
			printf ("%s\n", inbuf);
   	}

  exit (0);
	}

	return 0;
}