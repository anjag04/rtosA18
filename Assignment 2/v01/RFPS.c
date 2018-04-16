/*
    Read 
    File
    Print to
    Screen

    based on l1ex3:
    
  Read a text from hard disc to a memory.
  This is done by
  1) execute a program through its command line
  2) the program includes open a text file and read contents of the text file
  3) input the contents to a specific location the will display them.
*/

#include <stdio.h>
#define CHARS_TO_READ 1
#define BUFFER_SIZE 256
#define LINES_TO_PRINT 14
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
// open a text file
    FILE* file = fopen (argv [1], "r");
    char strLine[BUFFER_SIZE];
    char ch;
    if (file != NULL) 
    {
      for (int i = 0; i < LINES_TO_PRINT; i++)
      {
        fgets (strLine,BUFFER_SIZE,file); //read a line from the text file.
        printf ("%s", strLine);
      }
//read two characters
/*
        fread (&ch, sizeof (char), CHARS_TO_READ, file);
        printf ("%c", ch);

      fread (&ch, sizeof (char), CHARS_TO_READ, file);
      printf ("%c", ch);
*///read the remaining content of the line.
      fgets (strLine, BUFFER_SIZE, file); 
//read a line from the text file.
      printf ("%s\n", strLine);
    }
  }
}