#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main (void)
{
  #ifdef _POSIX_VERSION
    printf ("POSIX detected at compile time\n");
    printf ("POSIX Version: %ld\n",_POSIX_VERSION);
    printf ("POSIX.1\n");
    #ifdef _POSIX_JOB_CONTROL
      printf ("\t_POSIX_JOB_CONTROL\n");
    #endif
    #ifdef _POSIX_CHOWN_RESTRICTED
      printf ("\t_POSIX_CHOWN_RESTRICTED\n");
    #endif
    #ifdef _POSIX_SAVED_IDS
      printf ("\t_POSIX_SAVED_IDS\n");
    #endif
    #ifdef _POSIX_NO_TRUNC
      printf ("\t_POSIX_NO_TRUNC\n");
    #endif
    #ifdef _POSIX_VDISABLE
      printf ("\t_POSIX_VDISABLE\n");
    #endif
    #ifdef NGROUPS_MAX
      printf ("\tNGROUPS_MAX: %ld\n",(long)NGROUPS_MAX);
    #endif
    printf ("POSIX.4\n");
    #ifdef _POSIX_REALTIME_SIGNALS
      printf ("\t_POSIX_REALTIME_SIGNALS\n");
    #endif
    #ifdef _POSIX_PRIORITY_SCHEDULING
      printf ("\t_POSIX_PRIORITY_SCHEDULING\n");
    #endif
    #ifdef _POSIX_TIMERS
      printf ("\t_POSIX_TIMERS\n");
    #endif
    #ifdef _POSIX_ASYNCHRONOUS_IO
      printf ("\t_POSIX_ASYNCHRONOUS_IO\n");
    #endif
    #ifdef _POSIX_PRIORITIZED_IO
      printf ("\t_POSIX_PRIORITIZED_IO\n");
    #endif
    #ifdef _POSIX_SYNCRONIZED_IO
      printf ("\t_POSIX_SYNCHRONIZED_IO\n");
    #endif
    #ifdef _POSIX_FSYNC
      printf ("\t_POSIX_FSYNC\n");
    #endif
    #ifdef _POSIX_MAPPED_FILES
      printf ("\t_POSIX_MAPPED_FILES\n");
    #endif
    #ifdef _POSIX_MEMLOCK
      printf ("\t_POSIX_MEMLOCK\n");
    #endif
    #ifdef _POSIX_MEMLOCK_RANGE
      printf ("\t_POSIX_MEMLOCK_RANGE\n");
    #endif
    #ifdef _POSIX_MEMORY_PROTECTION
      printf ("\t_POSIX_MEMORY_PROTECTION\n");
    #endif
    #ifdef _POSIX_MESSAGE_PASSING
      printf ("\t_POSIX_MESSAGE_PASSING\n");
    #endif
    #ifdef _POSIX_SEMAPHORES
      printf ("\t_POSIX_SEMAPHORES\n");
    #endif
    #ifdef _POSIX_SHARED_MEMORY_OBJECTS
      printf ("\t_POSIX_SHARED_MEMORY_OBJECTS\n");
    #endif
  #else
    printf ("POSIX not available at compile time.\n");
  #endif
  printf ("POSIX runtime version: %ld\n",sysconf (_SC_VERSION));
  if (sysconf (_POSIX_JOB_CONTROL))
  {
    printf ("\t_POSIX_JOB_CONTROL\n");
  }
  if (sysconf (_POSIX_SEMAPHORES))
  {
    printf ("\t_POSIX_SEMAPHORES\n");
  }
  printf ("SC_JOB_CONTROL: %ld\n",sysconf (_SC_JOB_CONTROL));

  return 0;
}

