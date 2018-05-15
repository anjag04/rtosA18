/*
	Initialise.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void createPipeFork (int * ret, pid_t pid)
{
	int * fd = ret;
	char buf[20];
/* setup Pipe */
	pipe (fd);

	if (*fd == -1)
	{
		perror ("pipe");
		exit (1);
	}

		pid = fork ();
	

	if (pid == 0)
	{
	/* Child Process will write to mypipefd */
		printf ("Child Process\n");
		close (fd[0]);
		/* fd[1] is write */
//		write (fd[1], "Hello World!", 12);
	}
	else
	{
	/* Parent Process */
		printf ("Parent Process\n");
		close (fd[1]);
		/* fd[0] is read */
		read (fd[0], buf, 15);

//		printf ("buf: %s\n", buf);
	}

}