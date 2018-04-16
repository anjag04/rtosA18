#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[])
{
  time_t Mytime;
  struct tm *Mytm;

  Mytime = time(NULL);
  Mytm = localtime(&Mytime);

  int timeStart = Mytm->tm_sec;
  printf ("\ntimeStart: \n%s\n", ctime(&Mytime));

  for (int i = 0; i < 10; i++)
    printf ("%d Hello World!\n", i);

  int timeEnd = Mytm->tm_sec;
  printf ("\ntimeEnd: \n%s\n", ctime(&Mytime));

  printf ("secondsTaken: %d\n seconds", timeEnd - timeStart);

  return 0;
}

void startTime ()
{
    
}