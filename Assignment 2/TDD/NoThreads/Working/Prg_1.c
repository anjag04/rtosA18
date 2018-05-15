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

/*!< Struct for globally addressed data */
struct file_runner_struct
{
  FILE * inputFile;
  FILE * outputFile;

  //pipe

  char pipeWrite[BUFFER_SIZE];
  char pipeRead[BUFFER_SIZE];
  char fileWrite[BUFFER_SIZE];
};

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
 * @brief Creates file with unique filename bsed
 * 
 * @param fileWrite contents to be written to the file
 * @param mypipefd pipe to read from
 * @param f file to write to
 */
void writeFile(char * fileWrite, int * mypipefd, FILE * f) {
  if ( * mypipefd == -1) {
    printf("Failed to create and open the file.\n");
    exit(1);
  } else {
    // Write contents to file
    fprintf(f, fileWrite, f);
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
  //if File exists, store in buffer
  if (file != NULL) {
    //read one line from the text file.
    fgets(lineRead, BUFFER_SIZE, file);
  }
}

/*!
 * @brief Write buffer contents into pipe
 * 
 */
void writePipe() {

}

int main(int argc, char * * argv) {
    /* Check for input text file */
    if (checkInput(argc)) {
      printf("\nNo input file to read!\n");
      return 1;
    } 
    else
    {
      /* Initialise Functions */
      struct file_runner_struct FileData;
      time_t rawtime;
      char buffer[255];
      time( & rawtime);

      /* Create Pipe */
      int mypipefd[2];
      pipe(mypipefd);

      // create file with Unique eName /* SAVEFILE NAME GETS CHANGED HERE  ==IGNORE DYNAMIC FILE WARNINGS FOR THIS==*/
      FileData.outputFile = sprintf(buffer, "GenFile-%s.txt", ctime( & rawtime));

      // open a text file and print to screen
      FileData.outputFile = fopen(buffer, "w");

      /* Create Signal Variables */

      /* Create Threads */

      /* Thread A */

      /* Read Input */
      char * * argvinput = argv;
      FileData.inputFile = fopen(argv[1], "r");
/*      char pipeWrite[BUFFER_SIZE];
      char pipeRead[BUFFER_SIZE];
      char fileWrite[BUFFER_SIZE];
*/      char ch;

      char endText[BUFFER_SIZE] = "end_header";

      char stringToFind[BUFFER_SIZE] = "end_header";
      char * ret = 0;
      int headerFlag = -1;
      //if File exists, store in buffer
      if (FileData.inputFile != NULL) {
        for (int i = 0; i < NUM_LINES; i++) 
        {
          //read one line from the text file.
          fgets(FileData.pipeWrite, BUFFER_SIZE, FileData.inputFile);
          write(mypipefd[1], FileData.pipeWrite, strlen(FileData.pipeWrite));

          /* Thread B Read from pipe to pipeRead */

          /* Thread C Copy to Buffer and Filter out Header */

          size_t fwSize = sizeof(FileData.fileWrite)/ sizeof (int);
          size_t etSize = sizeof(stringToFind)/ sizeof (int);
          strncpy (FileData.fileWrite, FileData.pipeWrite, etSize);

          // Raise a flag if end detected
            ret = strstr(FileData.fileWrite, stringToFind);

          // Write to file if flag raised
            if (ret != 0 || headerFlag != -1)
            {
              headerFlag++; 
            }

            else if (ret != 0)
            {
              printf ("Found end_header at %d\n", i);
            }
            /* This is what gets Printed To The Output File */
            if (headerFlag > 0)
            {
              writeFile(FileData.fileWrite, mypipefd, FileData.outputFile);
              printf ("%s\n",FileData.fileWrite);
            }
              
            // printf ("ret = %d\n", ret);
            // printf ("headerFlag = %d\n", headerFlag);

          int endMatch = strncmp (endText, FileData.fileWrite, etSize);
        }

      }
    }
      return 0;
    }

    /*!
     *@}
     */