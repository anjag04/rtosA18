/*
 * This program will write a message into a region
 * of shared memory that has already been created
 * for it by shm-reader.c
 * If shm-reader hasn't been run first to set the 
 * region of shared memory up, then it will terminate
 * with a message.
 */

#define     _POSIX_C_SOURCE 199309L

#include    <stdio.h>       /* printf, sprintf */
#include    <unistd.h>      /* POSIX et al */
#include    <limits.h>      /* PAGESIZE */
#include    <stdlib.h>
#include    <fcntl.h>       /* O_RDWR et al */
#include    <sys/stat.h>    /* S_IRWXU et al */
#include    <sys/param.h>   /* PAGESIZE et al */
#ifdef	 _POSIX_SHARED_MEMORY_OBJECTS
 #include    <sys/mman.h>    /* shm_open, mmap */
#endif
#include    <sys/types.h>   /* waitpid */
#include    <sys/wait.h>    /* waitpid */
#include    <signal.h>      /* sigaction */

#define SHMNAME     "/mysharedmem"


int main (void)
{
  int d;
  char *addr;
  char writersMessage[] = "Hello from shm-writer!\n";

  /* Single argument is the name of the shared memory region to map in */
  if ((d = shm_open (SHMNAME, O_RDWR, S_IRWXU)) < 0)
  {
    perror ("shm_open");
    exit (2);
  }
  
  addr = (char *)mmap (NULL, (size_t)1024, PROT_READ|PROT_WRITE, MAP_SHARED, d, 0);
  if (addr == MAP_FAILED)
  {
	perror ("mmap");
	exit (3);
  }

  printf ("SHM-WRITER: I'm going to write %s", writersMessage);
  sprintf (addr, writersMessage);
  printf ("SHM-WRITER: There, I've done it!\n");

  if (munmap ((void *)addr, (size_t)1024) < 0)
  {
	perror ("munmap");
	exit (4);
  }

  close(d);

  return 0;
}