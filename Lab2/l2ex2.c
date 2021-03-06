/*
  Exercise 2: write a program to use bounded buffer. 
  The program should define a buffer and can store characters. 
  We input characters from command line, the program begin to print out all the input characters when the buffer is full. 
  An example code is given below
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define BUFFER_SIZE 15
#define TRUE 1

char *text = "Jian Zhang OS Code";

typedef struct
{
  char elem;
}

item;

int main()
{
  item buffer[BUFFER_SIZE];
  int in = 0;
  int out = 0;

  item next_produced, next_comsumed;
  while (TRUE)
  {
    printf("Begin produce:\n");
    while (1)
    {
      if (((in + 1) % BUFFER_SIZE) == out)
      {
        printf("\nFull: %d\n", in); break;
      }//do nothing 

      next_produced.elem = text[in]; // assign the text to next_produced!
      buffer[in] = next_produced;
      printf("%c", next_produced.elem); // added for more explanation
      in = (in + 1) % BUFFER_SIZE;
    }

    printf("\nBegin comsume:\n");
    while (TRUE)
    {
      if (in == out)
      {
        printf("\nComsume complete, it is empty now.\n"); break;
      }//do nothing 
      
      next_comsumed = buffer[out];
      printf("%c", next_comsumed.elem);//added for more explanation
      out = (out + 1) % BUFFER_SIZE;
/*comsume the item in next consumed*/
    }
    break;
  }
}
