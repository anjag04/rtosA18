/*
	Assigment 2 Main.c
	RTOS Assignment2
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BLOCK_SIZE 4096

int main (int argc, char * argv[2])
{
	int c = argc;
	char * v[2] = *argv[2];
  /* Setup Threads */
	/* Setup Pipe */
	/* Read File */
	return fileRead (c, v[2]);
	/* Write one line of file text to pipe */
}

int fileRead (int argc, char * argv[2])
{
   int fd=-1;
   ssize_t bytes_read=-1;
   int i=0;
   char buff[50];
   //Arbitary size for the buffer?? How to optimise.
   //Dynamic allocation is a choice but what is the
   //right way to relate the file size to bufffer size.

   fd = open("./file-to-buff.txt",O_RDONLY);
   if(-1 == fd)
   {
      perror("Open Failed");
      return 1;
   }

   while((bytes_read=read(fd,buff,BLOCK_SIZE))>0)
   {
      printf("bytes_read = %d\n",bytes_read);
   }

   //Test to characters read from the file to buffer.The file contains "Hello"
   while(buff[i]!='\0')
   {
      printf ("buff[%d] = %c\n",i,buff[i]);
      i++;
      //buff[5]=\n-How?
   }
   //buff[6]=`\0`-How?
   close(fd);
	 return 0;
}