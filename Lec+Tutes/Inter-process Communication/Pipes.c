#include <sys/types.h>

#define MESSLENGTH 80

char pourIntoPipe[] = "This has been through the pipe!\n";
char collectFromPipe[MESSLENGTH];

int main (void)
{
	int n, fd[2];// file descriptors: fd[0] – read file, fd[1]-write file
	pid_t pid;
	
	if (pipe (fd) < 0 )
		perror ("pipe error");
	if ((pid = fork ()) < 0 )
		perror ("fork error");
	else if (pid > 0)
	{                      /* parent will do the writing this time */
		close (fd[0]);        /* we don't want the reading end at all */
		write (fd[1], pourIntoPipe, strlen (pourIntoPipe));
	}
	else 
	{
		close (fd[1]);        /* child will do the reading. */
		n = read (fd[0], collectFromPipe, MESSLENGTH);
		printf ("%s", collectFromPipe);
	}
	exit(0);
}