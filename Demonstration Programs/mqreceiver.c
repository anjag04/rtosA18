/*
 * A test of POSIX.4 Message Passing
 * This program will create the message queue
 * and allow another program to send something
 * using the message queue.
 *
 * THIS PROGRAM REQUIRES ELEVATED (ROOT) PRIVILEGES
 * SO AS A NORMAL USER, YOU WON'T BE ABLE TO RUN IT.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#ifdef _POSIX_MESSAGE_PASSING
 #include <mqueue.h>
#endif

int main (void)
{

#ifndef _POSIX_MESSAGE_PASSING
    printf ("POSIX.4 Message Passing is not supported!\n");
#else

    struct mq_attr    attributes;
    mqd_t             messageq;
    char  	      message[128];
    ssize_t	      messagelen;
    unsigned int      priority;

    attributes.mq_maxmsg = 100;  /* Number of messages that queue supports */
    attributes.mq_msgsize = 128; /* Size of each message in the queue */
    attributes.mq_flags = 0;     /* No special control flags, default is OK */

    messageq = mq_open ("/messageq", O_CREAT|O_RDONLY, S_IRWXU, &attributes);
    if (messageq == (mqd_t)-1)
    {
      perror ("mq_open");
      exit (1);
    }

    /* Use the queue here - send a message */
    messagelen = mq_receive (messageq, message, sizeof (message), &priority);
    if(messagelen < 0)
    {
	  perror ("mq_received");
	  exit (2);
    }

    printf ("Messagelength: %d\n", (int)messagelen);
    message[messagelen] = '\0'; /* Append a null character to the string */
    printf ("Message recevied - the message was: %s\n", message);
    printf ("The message priority was: %d\n", priority);

    /* Close the queue */
    if (mq_close (messageq) < 0)
    {
      perror ("mq_close");
	  exit (3);
    }

    /* Unlink (remove) message queue */
    if (mq_unlink("/messageq") < 0)
    {
      perror ("mq_unlink");
	  exit (4);
    }

#endif
    return 0;
}

