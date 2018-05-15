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
#define BUFFER_SIZE 200
#define NUM_LINES 15 /* Total Lines 15 */ /* End Header on Line 10*/ /* DETERMINE THIS BY READING FILE */
#define STRING_TO_FIND "end_header"

/*!< Struct for globally addressed data */
struct file_runner_struct
{
  FILE * inputFile;
  FILE * outputFile;

  //pipe

  char pipeWrite[BUFFER_SIZE];
  char pipeRead[BUFFER_SIZE];
  char fileWrite[BUFFER_SIZE];

  /* Flags Initialised to "not found" */
  int ret;
  int headerFlag;

  size_t fwSize;
  size_t etSize;

  int linesRead;
};

struct file_runner_struct FileData;

/*!
 * @brief Creates file with unique filename bsed
 * 
 * @param fileWrite contents to be written to the file
 * @param mypipefd pipe to read from
 * @param f file to write to
 */
void writeFile(char * fileWrite, char * mypipefd, FILE * f) {
  if (*FileData.fileWrite == -1) {
    printf("Failed to create and open the file.\n");
    exit(1);
  } 
  else 
  {
    // Write contents to file
    fprintf(f, fileWrite, f);
  }
}

void* threadC (void)
{
  printf("ThreadC\n");
/* Thread C Copy to fileNameBuffer and Filter out Header */
  char needle[BUFFER_SIZE] = "end_header";
  strncpy (FileData.fileWrite, FileData.pipeRead, FileData.etSize);
  // Raise a flag if end string detected
  printf ("Searching for phrase\n");
  FileData.ret = strstr(FileData.fileWrite, "end_header");
  printf ("FileData.ret = %d\n", FileData.ret);
  
  // set flag if phrase found
    if (FileData.ret != 0)
    {
      FileData.headerFlag++; 
    }

    
    if (FileData.ret != 0)
    {
      printf ("Found end_header at %d\n", FileData.linesRead);
      threadA ();
    }
    // print to screen if phrase found
    /* This is what gets Printed To The Output File */
    if (FileData.headerFlag > 0)
    {
      writeFile(FileData.fileWrite, FileData.pipeRead, FileData.outputFile);
      threadA();
    }
    // else
    // {
    //   threadA ();
    //   printf ("Try Again\n");
    // }

    if (!feof (FileData.inputFile))
    {
      threadA ();
    }


    if (feof(FileData.inputFile))
    {
      printf("EOF Reached!\n");
    }

    printf ("ret = %d\n", FileData.ret);
    printf ("headerFlag = %d\n", FileData.headerFlag);
}

void threadB (void)
{
  printf("ThreadB\n");
/* Thread B Read from pipe to pipeRead */
  strncpy (FileData.pipeRead, FileData.pipeWrite, FileData.etSize);
  threadC ();
}

void threadA (void)
{
  printf("ThreadA\n");
  if (FileData.inputFile != NULL) 
  {
    //read one line from the text file.
    fgets (FileData.pipeWrite, BUFFER_SIZE, FileData.inputFile);
    FileData.linesRead++;
    threadB ();
  }
}

/*!
 * @brief Checks if file to read is specified
 * 
 * @param argc the inputs to the program
 * @return 1 - if file not specified; 0 if correct
 */
int checkInput(int argc) {
  int input = argc;
  if (input != 2) {
    printf("The program should have one input parameter,\n");
    printf("the parameter is the document to be read.\n");
    printf("Usage: exe text_file_path\n");
    printf("Example: ./ txt_file\n");

    return 1;
  } else {
    return 0;
  }
}

/*!
 * @brief Read one line of text from a file
 * 
 * @param argv the inputs to the program
 */
void readLine(char * * argv) {
  char * * argvinput = argv;
  FILE * file = fopen(argv[1], "r");
  char lineRead[BUFFER_SIZE];
  char ch;
  //if File exists, store in fileNameBuffer
  if (file != NULL) {
    //read one line from the text file.
    fgets(lineRead, BUFFER_SIZE, file);
  }
}

/*!
 * @brief Write fileNameBuffer contents into pipe
 * 
 */
void writePipe() {

}

int main(int argc, char * * argv) {

// FileData.STRING_TO_FIND = "end_header";
FileData.ret = 0;
FileData.headerFlag = -1;
FileData.fwSize = sizeof(FileData.fileWrite)/ sizeof (int);
FileData.etSize = sizeof(STRING_TO_FIND)/ sizeof (int);
FileData.linesRead = 0;
    /* Check for input text file */
    if (checkInput(argc)) {
      printf("\nNo input file to read!\n");
      return 1;
    } 
    else
    {
      /* Initialise Functions */

      // Unique fileName Variables
      time_t rawtime;
      char fileNameBuffer[BUFFER_SIZE];
      time( & rawtime);

      /* Create Pipe */
      int mypipefd[2];
      pipe(mypipefd);

      // create file with Unique eName with write access /* SAVEFILE NAME GETS CHANGED HERE  ==IGNORE DYNAMIC FILE WARNINGS FOR THIS==*/
      FileData.outputFile = sprintf (fileNameBuffer, "GenFile-%s.txt", ctime( & rawtime));
      FileData.outputFile = fopen (fileNameBuffer, "w");

      /* Create Signal Variables */

      /* Read Input */
      char * * argvinput = argv;

      /*Threads */
      FileData.inputFile = fopen (argv[1], "r");
        threadA ();
    }
      return 0;
    }

    /*!
     *@}
     */