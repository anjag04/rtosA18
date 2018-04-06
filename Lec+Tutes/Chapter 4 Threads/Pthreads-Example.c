/*
Pthreads Example
*/

#include <pthread.h>
#include <stdio.h>

int sum /* this data is shared by the thread(s) */
void *runner (void *param); /*threads call this function */

int main (int argc, char *argv[])
{
	pthread_t tid /* the thread identifier */
	pthread attr_t attr /* set of thead attributes */

	if (argc !=2) // ARgument number should be 2
	{
		fprintf (stderr, "usage: a.out <integer value> \n");
		return -1;
	}

	if (atoi (argv[1]) < 0)
	{
		fprintf (stderr, "%d must be >- 9 \n", atoi (argv[1]));
		return -1
	}

	/* get the default attributes */
	pthread_attr_init (&attr);
	/* create the thread */
	pthread_create (&tid, &attr, runner, argv[1]);
	/* wait for the thead to exit */
	pthread_join (tid, NULL);

	printf ("sum = %d \n", sum);
}

/* The thread will begin control in this function */
void *runner (void *param)
{
	int i, upper = atoi (paam);
	sum = 0;

	for (i = 1; i <= upper; i++)
		sum += i;

		pthread.exit (0);
}