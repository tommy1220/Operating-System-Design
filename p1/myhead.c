#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "support.h"

/*
 * head_file() - display the first numlines lines of stdin
 */
void head_file(int numlines) {
    /* TODO: Complete this function */
 // while ((opt = getopt(argc, argv, "hn:")) != -1) {
 //        switch(opt) {
 //          case 'h': help(argv[0]); break;
 //          case 'n': numlines = atoi(optarg); break;
 //NB:
 //n: means that after n, another extra parameter needs to be taken
 //and that's pointed from optarg, so n: ==> n numlines, where 
 //numlines is equal to the extra param I assign as stdin which
 //optarg points to

 //  
    char buff[1024];
  
    // read lines  
    while(numlines>0&&(NULL != fgets(buff, 1024, stdin))){  
    	
    	printf("%s", buff);  
    	numlines--;
    		
    	
    }  
     

}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s [OPTION]\n", progname);
    printf("Print the first 10 lines of STDIN\n");
    printf("  -nK    print the first K lines instead of the first 10\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
    /* for getopt */
    long opt;
    int numlines = 10; /* default number of lines */

    /* run a student name check */
    check_student(argv[0]);

    /* parse the command-line options.  For this program, we only support  */
    /* the parameterless 'h' option, for getting help on program usage, */
    /* and the parametered 'n' option, for getting the number of lines. */
    while ((opt = getopt(argc, argv, "hn:")) != -1) {
        switch(opt) {
          case 'h': help(argv[0]); break;
          case 'n': numlines = atoi(optarg); break;
          //n: means that after n, another extra parameter needs to be taken
          //and that's pointed from optarg, so n: ==> n numlines, where 
          //numlines is equal to the extra param I assign as stdin which
          //optarg points to
        }
    }

    /* no need for error checking here */
    head_file(numlines);
}
