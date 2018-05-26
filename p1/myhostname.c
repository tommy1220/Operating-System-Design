#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "support.h"
#include <netdb.h>
#include <sys/unistd.h>

/*
 * host() - Print the hostname of the machine on which this program is
 *          running, formatted a few different ways
 */

void host(void) {
    /* TODO: Complete this function */
    char originhost[256];
    if(gethostname(originhost, sizeof(originhost))!=0)
    {
    	perror("can't get hostname\n");
    	exit(-1);
    }
    else
    {
    	int size=strlen(originhost);
    	char temp[256];
    	int i;
    	//cupid lower
    	for(i = 0; i < size; i++)
    	{
      		if( originhost[i]>='A' && originhost[i]<='Z')
			{
				temp[i]=originhost[i]+32;
			}
			else
			{
				temp[i]=originhost[i];
			}
    	}
    	temp[i] = '\0';
    	printf("lowercase is %s\n", temp);
    	
    	//upper
    	for(i = 0; i < size; i++)
    	{
      		if( originhost[i]>='a' && originhost[i]<='z')
			{
				temp[i]=originhost[i]-32;
			}
			else
			{
				temp[i]=originhost[i];
			}
			
    	}
    	temp[i] = '\0';
    	printf("UPPERCASE is %s\n", temp);
    	//jumbled
        for(i = 0; i < size; i+=2)
        {
            if( originhost[i]>='A' && originhost[i]<='Z')
            {
                temp[i]=originhost[i]+32;
            }
            else
            {
                temp[i]=originhost[i];
            }
        }
        temp[i] = '\0';

		printf("jumbled case is %s\n",temp);
		//reversed
		for(i = 0; i < size; i++)
    	{
      		temp[i] = originhost[size-i-1];
    	}
    	temp[i] = '\0';
    	printf("reversed case is %s\n", temp);
    }
}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s\n", progname);
    printf("Display the hostname of the machine\n");
    printf("The name will be displayed four ways, in the following order, on "
           "four lines:\n");
    printf("  all lowercase\n");
    printf("  ALL UPPERCASE\n");
    printf("  mIxEd LoWeRaNdUpPeR\n");
    printf("  emantsoh (i.e., reversed)\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
    /* for getopt */
    long opt;

    /* run a student name check */
    check_student(argv[0]);

    /* parse the command-line options.  For this program, we only support  */
    /* the parameterless 'h' option, for getting help on program usage. */
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
          case 'h': help(argv[0]); break;
        }
    }

    /* no need to look at arguments before calling the code */
    host();
}
