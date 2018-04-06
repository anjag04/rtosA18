/*
==POSIX version testing program==
*/

#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309 // later versionSeptember 1993
#include <unistd.h>  // need to check this file and get info.

main ()
{
	#ifndef_POSIX_VERSION
		printf ("POSIX is not supported! \n");
	#else /* POSIX version */
		#if _POSIX_VERSION == 199009
			printf ("POSIX.1 is supported but not POSIX.4 \n");
		#else#if _POSIX_VERSION >= 199309
			printf ("POSIX.1 and POSIX.4 are supported \n");
		#else 
			printf ("Strange POSIX version between 199009 and 199309 \n");
			#endif
		#endif
	#endif/* _POSIX_VERSION */
}