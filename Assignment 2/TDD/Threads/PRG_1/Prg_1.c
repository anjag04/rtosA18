/*!
 *  @addtogroup Assignment_2
 *  @{
 */

/*!
 * @inputFile Prg_1.c
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
#include <pthread.h>

#define BUFFER_SIZE 200
#define NUM_LINES 15 /* Total Lines 15 */ /* End Header on Line 10*/ /* DETERMINE THIS BY READING inputFILE */

/* Global Variables */

struct file_runner_struct
{
  FILE * inputFile;
  FILE * outputFile;
  //pipe 
  char pipeWrite[BUFFER_SIZE];
  char pipeRead[BUFFER_SIZE];
  char fileWrite[BUFFER_SIZE];
  char buffer[BUFFER_SIZE];
};

/*!
 * @brief Checks if inputFile to read is specified
 * 
 * @param argc the inputs to the program
 * @return 1 - if inputFile not specified; 0 if correct
 */
int checkInput(int argc) {
  int input = argc;
  if (input != 2) {
    printf("The program should have one input parameter,\n");
    printf("the parameter is the document to be read.\n");
    printf("Usage: exe inputtext_File_path\n");
    printf("Example: ./ inputtxt_File\n");

    return 1;
  } else {
    return 0;
  }
}

/*!
 * @brief Creates inputFile with unique inputFilename bsed
 * 
 * @param fileWrite contents to be written to the inputFile
 * @param mypipefd pipe to read from
 * @param f inputFile to write to
 */
void writeFile(char * fileWrite, int * mypipefd, FILE * f) {
  if ( * mypipefd == -1) {
    printf("Failed to create and open the inputFile.\n");
    exit(1);
  } else {
    // Write contents to inputFile
    fprintf(f, fileWrite, f);
  }
}

/*!
 * @brief Read one line of text from a inputFile
 * 
 * @param argv the inputs to the program
 */
void * readLine(void * arg) 
{
  char * * argvinput = arg;
  
  FILE * inputFile = fopen(arg, "r");

  char lineRead[BUFFER_SIZE];
  char ch;
  
  //if inputFile exists, store in buffer
  if (inputFile != NULL) {
    //read one line from the text inputFile.
    fgets(lineRead, BUFFER_SIZE, inputFile);
  }

  return lineRead;
}

/*!
 * @brief Write buffer contents into pipe
 * 
 */
void writePipe() {

}

int main(int argc, char * * argv) {
    /* Check for input text inputFile */
    if (checkInput(argc)) {
      printf("\nNo input inputFile to read!\n");
      return 1;
    } 
    else 
    {
      /* Initialise Functions */
      //		int mypipefd;

      struct file_runner_struct FileData;
      time_t rawtime;
      time( & rawtime);

      /* Create Pipe */
      int mypipefd[2];
      pipe(mypipefd);

      // create inputFile with Unique eName /* inputSAVEFILE NAME GETS CHANGED HERE  ==IGNORE DYNAMIC inputFILE WARNINGS FOR THIS==*/
      const char * inputnamedFile = sprintf (FileData.buffer, "inputGenFile-%s.txt", ctime( & rawtime));

      // open a text inputFile and print to screen
      FileData.inputFile = fopen(FileData.buffer, "w");

      /* Create Signal Variables */

      /* Create Threads */
      // Thread IDs
      pthread_t tidA;
      pthread_t tidB;
      pthread_t tidC;

      // Create Attributes
      pthread_attr_t attrA;
      pthread_attr_t attrB;
      pthread_attr_t attrC;

      pthread_attr_init (&attrA);
      pthread_attr_init (&attrB);
      pthread_attr_init (&attrC);

      /* Thread A */

      /* Read Input */
/*      char * * argvinput = argv;
      inputFILE * inputFile = fopen(argv[1], "r");

*/      pthread_create (&tidA, &attrA, readLine, &argv);

// Wait until thread is done

        pthread_join (tidA, NULL);

printf ("Reaches pipeWrite\n");
      char ch;

      char endText[BUFFER_SIZE] = "end_header";

      char phraseToFind[BUFFER_SIZE] = "end_header";
      char * ret = 0;
      int headerFlag = -1;
      //if inputFile exists, store in buffer
      if (FileData.inputFile != NULL) {
        for (int i = 0; i < NUM_LINES; i++) 
        {
          //read one line from the text inputFile.
          fgets(FileData.buffer, BUFFER_SIZE, FileData.inputFile);
          write(mypipefd[1], FileData.pipeWrite, strlen(FileData.pipeWrite));

          /* Thread B Read from pipe to pipeRead */

          /* Thread C Copy to Buffer and Filter out Header */

          size_t fwSize = sizeof(FileData.fileWrite)/ sizeof (int);
          size_t etSize = sizeof(endText)/ sizeof (int);
          strncpy(FileData.fileWrite, FileData.pipeWrite, etSize);

          // Raise a flag if end detected
            ret = strstr(FileData.fileWrite, phraseToFind);

          // Write to inputFile if flag raised
            if (ret != 0 || headerFlag != -1)
            {
              headerFlag++;
              printf ("end_header found!");
            }

            else if (ret != 0)
            {
              printf ("Found end_header at %d\n", i);
            }
            /* This is what gets Printed To The Output inputFile */
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