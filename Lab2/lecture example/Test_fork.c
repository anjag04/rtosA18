/*
fork() creates a new process by duplicating the calling process. 
The new process, referred to as the child, is an exact duplicate 
of the calling process.
On success, the PID of the child process is returned in the parent, 
and 0 is returned in the child. On failure, -1 is returned in the parent, 
no child process is created, and errno is set appropriately.
*/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid;
	/* fork a child process */
	pid=fork();
	
	printf("pid order: pid=%d\n",pid);//to see the pid execute order

	if(pid<0){/* error occurred*/
	  fprintf(stderr, "Fork Failed");
	  return 1;
	}
	else if(pid ==0){/* child process*/
	  printf("Child Begins, to do ls operation, pid=%d\n",pid);

          // after run this line, the child is ruturn. 
	  // If you do not want return now, comment this line to see what the fork run.
	execlp("/bin/ls","ls",NULL); // replace the current process with a new process
          printf("The process is still in the child process, pid=%d\n",pid);/*this line will not run, because the above line execlp () has process */	      }
	 else //If comment this line, child will both run the following lines. 
        {/* parent process*/
	    /*this line is very interesting to look at*/
	    printf("THis is the parent process, pid=%d\n\n",pid);
	/* parent will wait for the child to complete*/
	    wait(NULL);
	    printf("\nChild Complete and back to Parent \n");
	}
	printf("see what pid is now: pid=%d\n",pid);//to see the pid execute order
	return 0;
}
