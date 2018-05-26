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
  int x = numlines;
  // char * line = NULL;
  // size_t len = 0;
  // ssize_t read;
  //     while(x>0)
  //   {
  //     if((read = getline(&line, &len, stdin)) != -1)
  //       {
  //         printf("%s",line);
  //       }
  //     else
  //       {
  //         break;
  //       }
  //     x--;
  //   }

    char *line=NULL;
    size_t length=0;
    ssize_t r;
    while((r=getline(&line,&length,stdin))!=-1){
      if(x>0){
        printf("%s",line);
      }
      else{break;}
      x--;
    }
    free (line);
    exit(EXIT_SUCCESS);

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
    //check_student(argv[0]);

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
