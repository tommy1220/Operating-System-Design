#include <getopt.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "support.h"
#include <unistd.h>
volatile bool input=false;
volatile bool alrm=false;
volatile bool kill=false;
void sigf(int);
void sigFunc(long);
void sigIntIGN(int);
void sigIntHand();
void sigkill(int);
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
  signal(SIGKILL,sigkill);
  alarm(10);
  while(1) sigFunc(s);
}


void sigFunc(long start){
    struct itimerval end;
    if (input)  sigIntHand();
    if(kill) kill=false;
    else if(alrm){
    gettimeofday(&end.it_interval, NULL);
    long e=end.it_interval.tv_sec;
    long itrpt = e-start;
    fprintf(stderr, "Program ran for %ld seconds\n", itrpt);
    alrm=false;
    exit(1);
    }
      
}

void sigIntHand(){
      fprintf(stderr,"\n --\n|no|\n --\n\n");
    signal(SIGINT, sigIntIGN);
    input=false;
}
void sigf(int sig){
  alrm=true;
}

void sigIntIGN(int sig){
    signal(SIGINT,SIG_IGN);
    input=true;
}

void sigkill(int sig){
   kill=true;
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
    check_student(argv[0]);

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
