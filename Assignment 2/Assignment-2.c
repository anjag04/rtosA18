#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[])
{
  time_t mytime;
  struct tm *mytm;

  mytime = time(NULL);
  mytm = localtime(&mytime);

  printf ("\ntimeStart: \n%s\n", ctime(&mytime));
  int timeStart = mytm->tm_sec;

  printf ("Hello World!\n");

  int timeEnd = mytm->tm_sec;

  printf ("\ntimeEnd: \n%s\n", ctime(&mytime));

  printf ("secondsTaken: %d\n seconds", timeEnd - timeStart);

  return 0;
}

void startTime ()
{

}