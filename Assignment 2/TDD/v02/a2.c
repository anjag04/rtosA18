/*
 v02 TDD: Input file is passed into program and output file is created with same contents
*/

#include "a2.h"

int main (int argc, char**argv)
{	
	if (checkInput (argc))
  {
    return 1;
  }
  
  else
  {
    readFile (argv);
	  writeFile ();
  }
	return 0;
}