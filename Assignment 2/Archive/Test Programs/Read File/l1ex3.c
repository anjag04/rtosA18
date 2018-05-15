/*
  Exercise 3: To help you understand the I/O operation and file-system manipulation:

  Read a text from hard disc to a memory.
  This is done by
  1) execute a program through its command line
  2) the program includes open a text file and read contents of the text file
  3) input the contents to a specific location the will display them.

  Compile: gcc l1ex3 -o l1ex3
  Use: ./l1ex3 file.txt
*/

#include <stdio.h>
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
    char strLine[256];
    char ch;
    if (file != NULL) 
    {
      fgets (strLine,256,file); //read a line from the text file.
      printf ("%s\n", strLine);
//read two characters
      fread (&ch, sizeof (char), 1, file);
      printf ("%c", ch);
      fread (&ch, sizeof (char), 1, file);
      printf ("%c", ch);
//read the remaining content of the line.
      fgets (strLine, 256, file); 
//read a line from the text file.
      printf ("%s\n", strLine);
    }
  }
}