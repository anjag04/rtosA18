/*
    Read 
    File
    Print to
    Screen
    Write to
    File

    based on l1ex3 & https://www.youtube.com/watch?v=dP3N8g7h8gY:
    
  Read a text from hard disc to a memory.
  This is done by
  1) execute a program through its command line
  2) the program includes open a text file and read contents of the text file
  3) input the contents to a specific location the will display them.
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define CHARS_TO_READ 1
#define BUFFER_SIZE 256
#define LINES_TO_PRINT 15
#define FILE_CHARS 25
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
// open a text file and print to screen
    int fd;
    char buf[FILE_CHARS];

    fd = open ("WriteHere.txt", O_CREAT | O_WRONLY, 0600);
    if (fd == -1)
    {
      printf ("Failed to create and open the file.\n");
      exit (1);
    }
    FILE* file = fopen (argv [1], "r");
    char strLine[BUFFER_SIZE];
    char ch;
    if (file != NULL) 
    {
      for (int i = 0; i < LINES_TO_PRINT; i++)
      {
        fgets (strLine,BUFFER_SIZE,file); //read a line from the text file.
        printf ("%s", strLine);
        write (fd, strLine, FILE_CHARS);
      }

/* PIPE */


      printf ("\n");

    close (fd);

   }
  }
}