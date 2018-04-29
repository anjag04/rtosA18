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
#define BUFFER_SIZE 50
#define NUM_LINES 15 /* Total Lines 15 */ /* End Header on Line 10*/ /* DETERMINE THIS BY READING FILE */

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
      //		int mypipefd;
      time_t rawtime;
      char buffer[255];
      time( & rawtime);

      /* Create Pipe */
      int mypipefd[2];
      pipe(mypipefd);

      // create file with Unique eName /* SAVEFILE NAME GETS CHANGED HERE  ==IGNORE DYNAMIC FILE WARNINGS FOR THIS==*/
      const char * namedFile = sprintf(buffer, "GenFile-%s.txt", ctime( & rawtime));

      // open a text file and print to screen
      FILE * f = fopen(buffer, "w");

      /* Create Signal Variables */

      /* Create Threads */

      /* Thread A */

      /* Read Input */
      char * * argvinput = argv;
      FILE * file = fopen(argv[1], "r");
      char pipeWrite[BUFFER_SIZE];
      char pipeRead[BUFFER_SIZE];
      char fileWrite[BUFFER_SIZE];
      char ch;

      char endText[BUFFER_SIZE] = "end_header";

      char needle[BUFFER_SIZE] = "end_header";
      char * ret = 0;
      int headerFlag = -1;
      //if File exists, store in buffer
      if (file != NULL) {
        for (int i = 0; i < NUM_LINES; i++) 
        {
          //read one line from the text file.
          fgets(pipeWrite, BUFFER_SIZE, file);
          //Check what is being written to pipe
          printf("pipeWrite %%s = %s\n", pipeWrite);
          // printf("pipeWrite %%d = %d\n", pipeWrite);
          // printf("pipeWrite %%c = %c\n", pipeWrite);
          // write buffer contents to pipe
          write(mypipefd[1], pipeWrite, strlen(pipeWrite));

          /* Thread B  */

          /* Thread C */

          size_t fwSize = sizeof(fileWrite)/ sizeof (int);
          size_t etSize = sizeof(endText)/ sizeof (int);
          strncpy(fileWrite, pipeWrite, etSize);

          // printf("endText %%d = %d\n", endText);
          // printf("sizeOf (endText) %%d = %d\n", etSize);
          // printf("sizeOf (fileWrite) %%d = %d\n", fwSize);

          // Raise a flag if end detected
            ret = strstr(fileWrite, needle);

          // Write to file if flag raised
            if (ret != 0 || headerFlag != -1)
            {
              writeFile(fileWrite, mypipefd, f);
              headerFlag++;
            }

            if (ret != 0)
            {
              printf ("Found end_header at %d\n", i);
            }
            printf ("ret = %d\n", ret);
            printf ("headerFlag = %d\n", headerFlag);

          int endMatch = strncmp (endText, fileWrite, etSize);
        }

      }
    }
      return 0;
    }

    /*!
     *@}
     */