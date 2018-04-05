#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/* A simple program that installs a replacement signal handler
   for the SIGINT (interactive termination using ^C) signal.
   It's not a particularly good example program, because it
   doesn't reinstall the default hander before exiting. */


/* This function is the signal handler, it will be automatically
   invoked whenever the signal arrives at the process - this 
   happens irrespective of the activities being carried out by
   the process at this time. */
void ouch (int sig)
{
    printf ("OUCH! - I got signal %d\n", sig);
}


/* Execution entry point. */
int main ()
{
    struct sigaction act;

    act.sa_handler = ouch; /* Pointer to function. */

    if (sigemptyset(&act.sa_mask) < 0)
    {
	    printf ("Error: sigemptyset () failed, terminating!\n");
	    exit (1);
    }
    act.sa_flags = 0;


    if (sigaction(SIGINT, &act, 0) < 0)
    {
	    printf ("Error: sigaction() failed, terminating!\n");
        exit(2);
    }

    /* If we've got this far, then everything is working, so
       we can enter an infinite loop and wait for the signals
       to arrive. */
    while (1) 
    {
       printf ("Hello World!\n");
       sleep (1);
    }

    return 0; /* We never get here, in this program. */
}