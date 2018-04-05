/*
 *   About the simplest possible pthread demo.
 *
 *   Create two independent threads and let them
 *   run unconstrained to completion.
 *
 *   It may be necessary to supply the -lrt option to
 *   link with the librt library.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void function (void *);


int main (void)
{
  pthread_t	one, two;

  if (pthread_create (&one, NULL, (void *)function, (void *)"Hello from thread 1") != 0)
  {
    perror ("pthread_create");
    exit (1);
  }
  
  if (pthread_create (&two, NULL, (void *)function, (void *)"Hello from thread 2") != 0)
  {
	perror ("pthread_create");
	exit (2);
  }

/* Try commenting out the following line and see what happens */
  sleep (10);

  return 0;
}

/* The function for the threads to share. */
void function (void *arg)
{
  int l;

  for (l = 0; l < 1000000; l++)
  {
    printf ("%s\n", (char *)arg);
	fflush (stdout);
  }

  return;
}