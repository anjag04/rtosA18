

#include <stdio.h>

int main (int argc, char**argv)
{
	int x = argc;
	char y = **argv;
	char *z = *argv;
	printf ("argc = %d \n", x);
	printf ("**argv = %d \n", y);
	printf ("argv = %d \n", z);
	return 0;
}