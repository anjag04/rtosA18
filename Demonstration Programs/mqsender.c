/*
 * A test of POSIX.4 Message Passing
 * This program will send something via a 
 * message queue, to the companion program mqreceiver.c
 * 
 *
 * THIS PROGRAM REQUIRES ELEVATED (ROOT) PRIVILEGES
 * SO AS A NORMAL USER, YOU WON'T BE ABLE TO RUN IT.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#ifdef _POSIX_MESSAGE_PASSING
 #include <mqueue.h>
#endif

int main (void)
{

#ifndef _POSIX_MESSAGE_PASSING
    printf ("POSIX.4 Message Passing is not supported!\n");
#else

    mqd_t             messageq;
    char * message    = "A message for the POSIX.4 Message Queue";

    messageq = mq_open ("/messageq", O_WRONLY);
    if (messageq == (mqd_t)-1)
    {
      perror ("mq_open");
      exit (1);
    }

    printf ("About to send the message ...");
    /* Use the queue here - send a message. Arbitrary priority of 8. */
    if (mq_send(messageq, message, strlen(message), 8) < 0)
    {
	  perror ("mq_send");
	  exit (2);
    }

    printf ("DONE!\n");

    /* Close the queue */
    if (mq_close (messageq) < 0)
    {
      perror ("mq_close");
	  exit (3);
    }

#endif
    return 0;
}