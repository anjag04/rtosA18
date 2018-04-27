/*
	ta.h
*/

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