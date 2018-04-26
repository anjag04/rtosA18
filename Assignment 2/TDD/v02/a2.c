/*
 v02 TDD: Input file is passed into program and output file is created with same contents
*/

#include "a2.h"

  Initialise ()
  {
    
  }

int main (int argc, char**argv)
{	
	if (checkInput (argc))
  {
    return 1;
  }
  
  else
  {
    // Initialise --> Start Timer, Create Pipe, Create Threads
    Initialise ();
    // Thread A --> read File, Write to Pipe
    readFile (argv);
    // Thread B --> read Pipe, Pass to C
    // Thread C --> read B, filter src, Write to File
	  writeFile ();
  }
  // Exit --> Stop Timer, Write to "shared"
	return 0;
}