/*
Ruuner + Mutex + Semaphore
- compile using gcc -pthread Runner+Mutex+Semaphore.c -o rms
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int sum;/*this data is shared by the threads*/
/* The mutex lock */
pthread_mutex_t mutex;
/* the semaphores */
sem_t one, two;
pthread_t tid1, tid2; //Thread ID
pthread_attr_t attr; //Set of thread attributes
void *runnerOne (void *param); /*thread one call this function*/
void *runnerTwo (void *param); /*thread two call this function*/
void initializeData ();
int main (int argc, char*argv[])
{
// pthread_t tid ;/*the thread identifier*/
// pthread_attr_t attr ;/*set of thread attributes*/

	if (argc != 2)
	{
		fprintf (stderr,"usage: a.out <integer value> \n");
		return -1;
	}

	if (atoi (argv[1])<0)
	{
		fprintf (stderr, "%d must be > = 0 \n",atoi (argv[1]));
		return -1;
	}

	initializeData ();
/* get the default attributes*/
	pthread_attr_init (&attr);
	pthread_create (&tid1,&attr,runnerOne, argv[1]);
/* create the thread */
	printf ("sum = %d\n", sum);
	pthread_create (&tid2,&attr, runnerTwo, argv[1]);
/*create the thread*/ 
	sem_post (&two); 
/* unlcok the two'semaphore */
// sem_post (&one); /* unlcok the ‘one'semaphore */
/*wait for the thread to exit*/
	pthread_join (tid1,NULL);
	pthread_join (tid2,NULL);
	printf ("sum = %d \n", sum);
}/* end of Main */

void initializeData () 
{
/* Create the mutex lock */
	pthread_mutex_init (&mutex, NULL);

/* Create the 'one' semaphore and initialize the value = 0 the subroutine 
call is blocked */   
	sem_init (&one, 0, 0); //

/* Create the 'two' semaphore and initialize the value = 0 the subroutine 
call is blocked */
	sem_init (&two, 0, 0);
/* Get the default attributes */
	pthread_attr_init (&attr);
}

/*The thread one will begin control 
in this function*/

void *runnerOne (void *param)
{
/* acquire the ‘one’ semaphore */
	sem_wait (&one);
/* acquire the mutex lock */
	pthread_mutex_lock (&mutex);
	
	int i,upper = atoi (param);
	sum = 0;
	
	for (i = 0; i <= upper; i++) 
		sum += 2 * i;
	
	printf ("thread one\n");
/* release the mutex lock */
	pthread_mutex_unlock (&mutex);
/* release and unlock the ‘two’ 
semaphore */
	sem_post (&two);
}

/*The thread two will begin control 
in this function*/
void *runnerTwo (void *param)
{
/* acquire the ‘two’ semaphore */
	sem_wait (&two);
/* acquire the mutex lock */
	pthread_mutex_lock (&mutex);

	int i,upper = atoi (param);
	sum = 10;

	for (i = 0; i <= upper; i++)
		sum += i;
	printf ("thread two \n");
/* release the mutex lock */
	pthread_mutex_unlock (&mutex);
/* release and unlock the 'one' 
semaphore */
	sem_post (&one);
}