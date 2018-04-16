/*
You are required to write a program to help you understand multi-thread and semaphore/mutex concepts. The program needs to create one global variable and two threads. 
In thread 1, the program needs to sum up from 1 to 100, and outputs “thread one” information. In thread 2, the program needs to sum up from -100 to -1, and outputs “thread two” information. 
The two threads need to run mutually. In more details of each thread inside, firstly, the program waits for a semaphore, secondly, the program is locked to only run this thread, thirdly, do the calculation, fourthly, unlock the program; fifthly, send a semaphore to another thread.
Also, the thread 2 runs firstly and send a semaphore to thread 1 when thread 2 finishes. Then, thread 1 begin to run until it finishes all its work. When the program finishes, it needs to release all the resource and exit correctly.
A program framework is given, you need to fill the program and satisfy the requirement.
Compile with: gcc l3ex1.c -o l3ex1 -pthread
Run with: ./l3ex1 50
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sumOf (int sumToValue);
int Sum;/*this data is shared by the threads*/
/* The mutex lock */
pthread_mutex_t mutex;
/* the semaphores */
sem_t one, two;
pthread_t tid1,tid2;       //Thread ID
pthread_attr_t attr; //Set of thread attributes

void *runnerOne (void *param);/*threads call this function*/
void *runnerTwo (void *param);/*threads call this function*/
void initializeData();

int main (int argc, char*argv[])
{
  pthread_t tid;/*the thread identifier*/
  pthread_attr_t attr;/*set of thread attributes*/

  if (argc!=2)
  {
	  fprintf (stderr,"usage: a.out <integer value>\n");
	  return -1;
  }
  
  if (atoi (argv[1]) < 0)
  {
	  fprintf (stderr,"%d must be > = 0\n", atoi (argv[1]));
	  return -1;
  }
  initializeData ();

  /*get the default attributes*/
  pthread_attr_init (&attr);
  
  /*create the thread 1*/
  pthread_create (&tid1, &attr, runnerOne, argv[1]);
  
  printf("\nThread 1 Created! Id = %d\n", tid1);

  /*create the thread 2*/
  // add your program 
  pthread_create (&tid2, &attr, runnerTwo, argv[1]);

  printf("\nThread 2 Created! Id = %d\n", tid2);
  
  /*send semaphore to thread 2 and begin the threads running*/
  sem_post (&two);
  /*wait for the thread to exit*/
  // add your program

  /* wait for the semaphore one */
  
}

/*The thread will begin control in this function*/
void *runnerOne (void *param)
{
  /* wait for the semaphore one */
  sem_wait (&one);
  
  /* mutex lock the program */
  pthread_mutex_lock (&mutex);
  
  /* calculation */
  int i, upper = atoi (param);
  
  for (i = 1; i <= upper; i++)
    Sum += i; 
  
  printf ("thread one\n");
  /* release the mutex lock */
  pthread_mutex_unlock (&mutex); 
  
  /* send semaphore to thread 2*/
  sem_post (&two);
}

/*The thread will begin control in this function*/
void *runnerTwo (void *param)
{
  /* wait for the semaphore two */
  // add your program 
    sem_wait (&two);
  
  /* mutex lock the program */
  // add your program 
  pthread_mutex_lock (&mutex); 
  
  /* calculation */
  // add your program
  printf ("\nTHREAD TWO!\n");
  int i, upper = atoi (param);
  
  for (i = 1; i <= upper; i++)
    Sum -= i; 

  /* release the mutex lock */
  // add your program 
  pthread_mutex_unlock (&mutex); 
  
  /* send semaphore to thread 1*/
  // add your program 
  sem_post (&one);
}

void initializeData () 
{
   Sum = 0;
   
   /* Create the mutex lock */
   pthread_mutex_init (&mutex, NULL);

   /* Create the one semaphore and initialize to 0 */
   sem_init (&one, 0, 0);

   /* Create the two semaphore and initialize to BUFFER_SIZE */
   sem_init (&two, 0, 0);

   /* Get the default attributes */
   pthread_attr_init (&attr);
}

int sumOf (int sumToValue)
{
  int sumCalc = sumToValue;
  int sum = 0;

  if (sumCalc > 0)
  {
    for (int i = 0; i < sumCalc; i++)
    {
      printf ("i = %d\n", i);
      Sum += i;
    }
  }
  else
  {
    for (int i = 0; i > sumCalc; i--)
    {
      sum += i;
    }
  }
  return sum;
}