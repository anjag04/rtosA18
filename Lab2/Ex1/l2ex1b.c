/*
  Read the page 46-47 of Lecture 2 ppt. Then, run the code in your own machine and  understand the code.

  ===  POSIX Consumer ===
  - run using gcc l2ex1b.c -lrt -o l2ex1b
*/

#include <sys/mman.h> //ADDED THIS TO FOR mmap ()
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main ()
{
/* the size (in bytes) of shared memory object */
  const int SIZE = 4096;
/* name of the shared memory object */
  const char *name = "OS";
/* shared memory file descriptor */
  int shm_fd;
/* pointer to shared memory object */
  void *ptr;

/*open the shared memory object */
  shm_fd = shm_open (name, O_RDONLY, 0666);

/* memory map the shared memory object */
ptr = mmap (0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

/* read from the shared memory object */
  shm_unlink (name);

  return 0;
}
