/*
	ta.h
*/

#include <stdio.h>
#define BUFFER_SIZE 256

void readLine (char ** argv)
{
	char ** argvinput = argv;
  FILE* file = fopen (argv [1], "r");
  char strLine[BUFFER_SIZE];
  char ch;
	//if File exists, store in buffer
  if (file != NULL) 
  {
		printf ("==File Contents==:\n\n");
/*    for (int i = 0; i < LINES_TO_PRINT; i++)
    {*/
    //read one line from the text file.
			fgets (strLine,BUFFER_SIZE,file);
      printf ("%s", strLine);
    //}
	}
}
