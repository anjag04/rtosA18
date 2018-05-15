/*
 * Simple pipe() demonstration. Parent writes
 * into pipe, child reads it and prints a 
 * message on completion.
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define MESSLENGTH 80

int main(void)
{
    int   n, fd[2];  /* An array of two ints for the file descriptors. */
    pid_t pid;

    if(pipe(fd) < 0)
    {
        perror("pipe error"); /* Using perror() for the first time. */
        exit(1);
    }

    /* Just for interest, print out the fd values. */
    printf("pipe() was successful, fds are %d, %d\n", fd[0], fd[1]);

    if((pid = fork()) < 0)
    {
        perror("fork error");
        exit(2);
    }
    else if(pid > 0)
    {
        /* Parent - parent will do the writing this time */
        char pourIntoPipe[] = "This has been through the pipe!\n";
        close(fd[0]);        /* we don't want the reading end at all */
        write(fd[1], pourIntoPipe, strlen(pourIntoPipe));

    } else {

	/* Child */
        char collectFromPipe[MESSLENGTH]; /* buffer space in child   */
        close(fd[1]);        /* child will do the reading. */
        n = read(fd[0], collectFromPipe, MESSLENGTH);
        collectFromPipe[n] = '\0'; /* put null char at end of string */
        printf("%s", collectFromPipe);
    }

    exit(0);
}