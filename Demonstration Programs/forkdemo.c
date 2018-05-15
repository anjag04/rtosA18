/*
 * Parent and child processes demonstrate unmanaged sharing of stdout
 * by discretely printing out single characters. Notice that the use
 * of C's block scoping has demonstrated - it's impossible for the 
 * parent to reference the "Hello " string, and equally impossible for
 * the child to reference the "World\n" string. This is because the
 * character arrays are declared as local variables to the blocks in
 * the switch() statement.
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	pid_t childpid;

	switch (childpid = fork ())
        {
       	    case -1: printf ("Problem with fork(), terminating!\n");
		     exit (1);
		     break; /* redundant */ 
	    case 0:  /* Child process */
		     {
			char *str = "Hello ";
			
			while (*str)
			{
		       printf ("%c", *str);
			   str++;
			   fflush (stdout);
			   sleep (1); 
			}
		     }
		     break;
	    default: /* Parent process */
		     {
		        char *str = "World\n";
	
			while (*str)
			{
		       printf ("%c", *str);
			   str++;
			   fflush (stdout);
			   sleep (1);
			}
		     }
		     break;
        }
    exit(0);
}