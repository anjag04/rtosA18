/*
==C Progam Forking Separate Process==
*/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //NEEDED for wait (NULL)

int main ()
{
  pid_t pid;
  /* fork a child process */
  pid = fork ();
  printf ("pidorder: pid = %d \n", pid); //to see thepidexecute order
  if (pid < 0)
  {
/* error occurred*/
    fprintf (stderr, "Fork Failed");
    return 1;
  }
  else if (pid==0)
  {
/* child process*/
    printf ("Child Begins, to do ls operation,pid = %d \n", pid);
    execlp ("/bin/ls","ls", NULL); //run the instructor execlp and complete the childprocess.
  }
  else //If comment this line, parent andchild will both run the following lines.
  {
/* parent process*/
/* parent will wait for the child to complete*/
    wait (NULL);
    printf ("\nChildComplete and back to Parent\n");
  }
  printf ("see what dpid is now: pid = %d \n", pid);//to see thepidexecute order
  return 0;
}d