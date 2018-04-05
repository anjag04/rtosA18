/*
 *   Takes a single commandline argument - which must
 *   be a 1 or a 2, for one thread and two threads
 *   respectively. Create the correspondong number of 
 *   threads to do a processor-intensive
 *   task and wait for them to finish.
 *
 *   The idea is to use the unix 'time' command to
 *   time how long the program takes to complete.
 *
 *   It will probably need the -lrt option to be added
 *   to link with the realtime library.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage (char *);
void function (void *);

int main (int argc, char *argv[])
{
  pthread_t	one, two;

/* Deal with the case of no commandline argument */
  if (argc == 1)
  {
    usage (argv[0]);
	exit (1);
  }

  switch (atoi(argv[1]))  /* Convert the commandline argument to an int */
  {
	case 1:  
	    printf ("Executing two consecutive function calls, with one thread\n");
		function (NULL);
		function (NULL);
	  break;
	
	case 2:  
	    printf ("Executing two concurrent function calls, with two threads\n");
	    if (pthread_create(&one, NULL, (void *)function, NULL) != 0)
		{
		  perror ("pthread_create");
		  exit (2);
		}
		
		if (pthread_create(&two, NULL, (void *)function, NULL) != 0)
		{
		  perror ("pthread_create");
		  exit (3);
		}
		 
/* The thread that executes the main() function, will be paused here
	 	    until the working threads complete and return. */
        if(pthread_join(one, (void **)NULL) != 0)
		{
		  perror ("pthread_join");
		  exit (4);
		}
        
        if (pthread_join(two, (void **)NULL) != 0)
		{
		  perror ("pthread_join");
		  exit (5);
		}
    		 break;

	default: usage (argv[0]);
  }

  return 0;
}

/* The function that has the work in it! */
void function (void *arg)
{
  long l;

  for (l = 0; l < 1000000000; l++);

  printf ("Thread finished\n");

  return;
}

/* A utility function, tells user how to use the program. */
void usage (char *programname)
{
  printf ("%s 1|2 for 1 thread or 2 threads respectively\n", programname);
  
  return;
}