/*
 * This program signals a semaphore which
 * has already been created for it by
 * waiter.c
 */


#define     POSIX_C_SOURCE 199309L

#define     exit _exit

#include    <stdio.h>
#include    <unistd.h>  /* POSIX et al */
#include    <fcntl.h>   /* for O_EXCL */
#include    <sys/stat.h>
#ifdef _POSIX_SEMAPHORES
  #include    <semaphore.h>   /* sem_* */
#endif


#define semname "/mysemaphore"

int main (void)
{
  sem_t *s;

    /* Open semaphore that's already been created. */
  s = sem_open (semname, O_EXCL);
    /* Check that this was done ... */ 
  if (s == SEM_FAILED)
  {
    perror("sem_open");
    exit(1);
  }

  printf ("Now doing sem_post() ...\n");

  /* Attempt to do a post operation on the semaphore. */
  if (sem_post(s) < 0)
  {
    perror ("sem_post");
    exit (2);
  }

  /* We're finished, so time to close up. */
  if (sem_close(s) < 0)
  {
    perror ("sem_close");
    exit (3);
  }
    
  return 0;
}