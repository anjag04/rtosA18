/*
 * This program makes a named semaphore with initial
 * value of zero and then waits on it to be incremented,
 * before removing it.
 */


#define     POSIX_C_SOURCE 199309L

#define     exit _exit

#include    <stdio.h>
#include    <unistd.h>        /* POSIX et al */
#include    <fcntl.h>	      /* for O_CREAT, O_EXCL */
#include    <sys/stat.h>
#ifdef _POSIX_SEMAPHORES
  #include    <semaphore.h>   /* sem_* */
#endif


#define semname "/mysemaphore"

int main (void)
{
  sem_t *s;

  /* Create semaphore with initial value of zero. */
  s = sem_open (semname, O_CREAT | O_EXCL, S_IRWXU, 0);
  /* Check that this was done ... */ 
  if (s == SEM_FAILED)
  {
    perror("sem_open");
    exit (1);
  }

  printf ("Semaphore \"semname\" has been created\n");

  printf ("Now attempting sem_wait() ...\n");

/* Attempt to do a wait operation on the semaphore. */
  if (sem_wait(s) < 0)
  {
    perror ("sem_wait");
    exit (2);
  }

/* We get to this point, only after some other process
       has done sem_post() for us! */
  printf ("Thanks!\n"); 

/* We're finished, so time to tidy up. */
  if (sem_close(s) < 0)
  {
    perror ("sem_close");
    exit (3);
  }
   
/* Remove the semaphore entirely. */ 
  if (sem_unlink(semname) < 0)
  {
    perror ("sem_unlink");
	exit (4);
  }
    
    return 0;
}