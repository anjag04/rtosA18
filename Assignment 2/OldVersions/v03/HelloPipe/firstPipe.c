/* first pipe example from Haviland */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE  16

char *msg1 = "This has";
char *msg2 = "been through";
char *msg3 = "the pipe!";

int main ()
{  
	char inbuf[MSGSIZE];

   int p[2], j;

   /* open pipe */

   if (pipe(p) == -1)
   {    
		 perror ("pipe call error");
     exit (1);
   }
  
   /* write down pipe */
   write (p[1], msg1, MSGSIZE);
   write (p[1], msg2, MSGSIZE);
   write (p[1], msg3, MSGSIZE);

   /* read pipe */
   for (j = 0; j < 3; j++)
   {   
		 read (p[0], inbuf, MSGSIZE);
     printf ("%s\n", inbuf);
   }

   exit (0);
}