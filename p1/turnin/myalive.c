#include <getopt.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "support.h"
#include <unistd.h>
volatile int sgf = 0;
void sigf(int);
void sigFunc(long);
void sigIntIGN(int);
/*
 * alive() - install some signal handlers, set an alarm, and wait...
 */
void alive(void) {
    /* TODO: Complete this function */
    /* Note: you will probably need to implement some other functions */
  struct itimerval start;
  gettimeofday(&start.it_interval, NULL);
  long s=start.it_interval.tv_sec;
  signal(SIGINT, sigIntIGN);
  signal(SIGALRM, sigf);
  alarm(10);
  while(1) sigFunc(s);
}


void sigFunc(long start){
    struct itimerval end;
    if (sgf==SIGINT){
    fprintf(stderr,"\n --\n|no|\n --\n\n");
    sgf = 0;
    signal(SIGINT, sigIntIGN);
    }
    
    else if(sgf==SIGALRM){
    gettimeofday(&end.it_interval, NULL);
    long e=end.it_interval.tv_sec;
    long itrpt = e-start;
    fprintf(stderr, "Program ran for %ld seconds\n", itrpt);
    exit(1);
    }
      
}
void sigf(int sig){
  sgf = sig;
}
void sigIntIGN(int sig){
    sgf=SIGINT;
    signal(SIGINT,SIG_IGN);
}
/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s\n", progname);
    printf("Swallow SIGINT, exit on SIGALARM\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
    /* for getopt */
    long opt;

    /* run a student name check */
    //check_student(argv[0]);

    /* parse the command-line options.  For this program, we only support  */
    /* the parameterless 'h' option, for getting help on program usage. */
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
          case 'h': help(argv[0]); break;
        }
    }

    /* no need to look at arguments before calling the code */
    alive();
}
