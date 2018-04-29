/*!
 *  @addtogroup Assignment_2
 *  @{
 */

/*!
 * @file Prg_1.c
 * 
 * @brief 
 * Compile Using: 
 * Run using: 
 * @author Ankit Jagannath (11036997)
 * @date 2018-04-30
 */

/*
	Library Declarations
*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256
#define NUM_LINES 15 /* DETERMINE THIS BY READING FILE */

/*!
 * @brief Checks if file to read is specified
 * 
 * @param argc the inputs to the program
 * @return 1 - if file not specified; 0 if correct
*/
int checkInput (int argc) 
{
  int input = argc;
  if (input != 2) 
	{
    printf ("The program should have one input parameter,\n");
    printf ("the parameter is the document to be read.\n");
    printf ("Usage: exe text_file_path\n");
    printf ("Example: ./ txt_file\n");

    return 1;
  } 
	else 
	{
    return 0;
  }
}

/*!
 * @brief Creates file with unique filename bsed
 * 
 * @param argc the inputs to the program
*/
void writeFile (char * fileWrite, int * mypipefd, FILE * f) 
{
  if (* mypipefd == -1) 
	{
    printf ("Failed to create and open the file.\n");
    exit (1);
  } 
	else 
	{
	// Write contents to file
    fprintf (f, fileWrite, f);
  }
}

/*!
 * @brief Read one line of text from a file
 * 
 * @param argv the inputs to the program
*/
void readLine (char ** argv) 
{
  char ** argvinput = argv;
  FILE * file = fopen (argv[1], "r");
  char lineRead [BUFFER_SIZE];
  char ch;
  //if File exists, store in buffer
  if (file != NULL) 
	{
    printf ("==Line Read==:\n");
  //read one line from the text file.
    fgets (lineRead, BUFFER_SIZE, file);
    printf ("%s", lineRead);
  }
}

/*!
 * @brief Write buffer contents into pipe
 * 
*/
void writePipe ()
{

}

int main (int argc, char * * argv) 
{
	/* Check for input text file */
  if (checkInput(argc)) 
	{
    printf ("\nNo input file to read!\n");
    return 1;
  } 
	else 
	{
	/* Initialise Functions */
//		int mypipefd;
		time_t rawtime;
		char buffer [255];
		time (&rawtime);

	/* Create Pipe */
		int mypipefd [2];
		pipe (mypipefd);


		// create file with Unique eName /* SAVEFILE NAME GETS CHANGED HERE  ==IGNORE DYNAMIC FILE WARNINGS FOR THIS==*/
		const char *  namedFile = sprintf (buffer, "GenFile-%s.txt", ctime ( &rawtime));

	// open a text file and print to screen
		FILE * f = fopen (buffer, "w");

    /* Create Signal Variables */

    /* Create Threads */

    /* Thread A */

    /* Read Input */
    char * * argvinput = argv;
    FILE * file = fopen (argv [1], "r");
    char pipeWrite [BUFFER_SIZE];
    char pipeRead [BUFFER_SIZE];
    char ch;
    //if File exists, store in buffer
    if (file != NULL) 
		{
      for (int i = 0; i < NUM_LINES; i++) 
			{
        //read one line from the text file.
        printf ("==Pipe INPUT==\n\n");
        //Check what is being written to pipe
        fgets (pipeWrite, BUFFER_SIZE, file);
        printf ("%s", pipeWrite);
        // write buffer contents to pipe
        write (mypipefd[1], pipeWrite, strlen(pipeWrite));
        // close pipe input
        close (mypipefd[1]);
        // signal Thread B

        /* Thread B */
        // read buffer contents to buffer
        read (mypipefd [0], pipeRead, BUFFER_SIZE);
        //Check what is being read from pipe
        printf ("\n==Pipe OUTPUT==\n");
        printf ("%s", pipeRead);
        // Signal Thread C
      

      /* Thread C */

      /*const*/ char * fileWrite = pipeWrite;

      writeFile (fileWrite, mypipefd, f);
			}
      // Signal Thread A
    }
  }

  return 0;
}

/*!
 *@}
 */