#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The sum calculated by the background thread
long long sum = 0;

/* Runner indicates function is a thread */
void* sum_runner (void * arg)
{
	long long * limit_ptr = (long long *) arg;
	long long limit = * limit_ptr;

	for (long long i = 0; i <= limit; i++)
	{
		sum += i;
	}

	// Sum is a global variable, so other threads can access

	pthread_exit(0);
}

int main (int argc, char ** argv)
{
	if (argc < 2)
	{
		printf ("Usage: %s <num>\n", argv[0]);
		exit (-1);
	}

	/* atoll:  Asciii To Long Long */
	long long limit = atoll (argv[1]);

	// Thread ID:
	pthread_t tid;

	// Create attributes
	pthread_attr_t attr;
	pthread_attr_init (&attr);

	// pthread_create arguments:
	// Address of Thread ID, Address off Attributes, 
	// Function to execute (no parentheses - pass function pointer, function arguments)
	pthread_create(&tid, &attr, sum_runner, &limit);

// wait until thread is done its work
	pthread_join(tid, NULL);
	printf ("Sum is %lld\n", sum);

	return 0;
}