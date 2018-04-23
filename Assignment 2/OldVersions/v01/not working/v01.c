/*
  Exercise 3: To help you understand the I/O operation and file-system manipulation:

  Read a text from hard disc to a memory.
  This is done by
  1) execute a program through its command line
  2) the program includes open a text file and read contents of the text file
  3) input the contents to a specific location the will display them.
*/

#include <stdio.h>
#define LINE_SIZE 2
#define NUM_CHARS 2

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
    char strLine[LINE_SIZE];
    char ch;
    if (file != NULL) 
    {
      fgets (strLine, LINE_SIZE, file); //read a line from the text file1
//      printf ("%s", strLine);

//read two characters
/*<!
  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

  The  function  fread() reads NUM_CHARS items of data, each sizeof (char) bytes long,
  from the stream pointed to by file,  storing  them  at  the  location
  given by ch.
*/
      fread (&ch, sizeof (char), NUM_CHARS, file);
      printf ("%c", ch);
/*      fread (&ch, sizeof (char), NUM_CHARS, file);
      printf ("%c", ch);
//read the remaining content of the line.
      fgets (strLine, LINE_SIZE, file);
//read a line from the text file.
        printf ("%s\n", strLine);
        */
    }
  }
}