/*
	ass.h
*/

/*
	Library Declarations
*/
#include <stdio.h>
#include <unistd.h>

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