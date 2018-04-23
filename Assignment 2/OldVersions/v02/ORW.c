/*
    Read 
    File
    Print to
    Screen

    based on https://www.youtube.com/watch?v=dP3N8g7h8gY
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define FILE_CHARS 25

int main (int argc, char *argv[])
{
  int fd;
  char buf[FILE_CHARS];

  /* write */

  fd = open ("helloWrite.txt", O_CREAT | O_WRONLY, 0600);

  if (fd == -1)
  {
    printf ("Failed to create and open the file.\n");
    exit (1);
  }

  write (fd, "Hello File Write World!\n", FILE_CHARS);

  close (fd);

  /* read */

  fd = open ("helloWrite.txt", O_RDONLY);
  
  if (fd == -1)
  {
    printf ("Failed to open and read the file.\n");
    exit (1);
  }

  read (fd, buf, FILE_CHARS);

  buf[FILE_CHARS-1] = '/0';

  printf ("buf %s\n", buf);

  close (fd);
    
  return 0;
}