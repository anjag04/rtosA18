/*! @file readFile.c
 *  @brief Function to read file and output contents to screen
 *  Compile: gcc readFile.c -o readFile
 *  Use: ./readFile data.txt
 *  @author Ankit Jagannath (11036997)
 *  @date 2018-04-08
 *  @addtogroup RTOSA18_Assignment2 [(readFile.c)]
 *  @{
 */

#include <stdio.h>

#define CHAR_SIZE 256
#define NUM_CHARS_TO_READ 5

/*!
 * @brief help function to describe use
 * @param no input
 * @return no return- instructions displayed on screen
 */
void help (void)
{
  printf ("The program should have one input parameter,\n");
  printf ("the parameter is the document to be read.\n");
  printf ("Usage: exe text_file_path\n"); 
  printf ("Example: ./readFile data.txt\n");
}

/*!
 * @brief main function
 * @param argc is the file to be read
 * @param **argv is (something... memory location?)
 * @return runtime error code, 0 if success
 */
int main (int argc, char**argv)
{
/*!< Call help function if filename and location not called */
  if (argc != 2)
    help();
  else
  {
  /*
    FILE *fopen(const char *path, const char *mode);
    The fopen() function opens the file whose name is 
    the string pointed to by path and associates a stream with it.
  */
/*!< file is a pointer to open filepath for reading */
    FILE* file = fopen (argv [1], "r");
    char strLine[CHAR_SIZE];
    char ch;
/*!< WHAT IS THIS CHECKING? */
    if (file != NULL) 
    {
    /*
    char *fgets(char *s, int size, FILE *stream);
    fgets() reads in at most one less than size characters 
    from stream and stores them into the buffer pointed to by s.  
    Reading  stops  after  an EOF or a newline.  
    If a newline is read, it is stored into the buffer.
    A terminating null byte ('\0') is stored after the last character in
    the buffer.
    */
/*!< get a line from the text file and store in buffer strLine. */
      fgets (strLine,CHAR_SIZE,file);
      printf ("%s\n", strLine);
    /*
    read two characters
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    The function fread() reads nmemb items of data, each size bytes long,
    from the stream pointed to by stream, storing them at the location
       given by ptr.
    */
/*!< Read one char FROM file and place IN ch */
      fread (&ch, sizeof (char), NUM_CHARS_TO_READ, file);
      printf ("%c", ch);
    /*      fread (&ch, sizeof (char), NUM_CHARS_TO_READ, file);
      printf ("%c", ch);
    

      read the remaining content of the line.

      fgets (strLine, CHAR_SIZE, file); 
      //read a line from the text file.
      printf ("%s\n", strLine);
    */
    }
    else
    {
      printf ("%c File contents empty", *argv[2]);
    }
  }
}

/*!
 * @}
 */