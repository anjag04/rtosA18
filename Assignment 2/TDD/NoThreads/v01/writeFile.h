/*
	Prototypes for destination file functions
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createFile (void)
{
// open a text file and print to screen
	int fd;
// createUniqueFileName

	time_t rawtime;
	char buffer [255];

	time (&rawtime);
	sprintf (buffer, "GenFile-%s.txt",ctime (&rawtime));

	//fd = open ("%s", buffer, O_CREAT | O_WRONLY, 0600);

	printf ("%s", buffer);
	fopen (buffer, "w");

	if (fd == -1)
	{
		printf ("Failed to create and open the file.\n");
    exit (1);
  }
}