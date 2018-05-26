#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "support.h"

/*
 * list_task() - read from stdin, determine the appropriate behavior, and
 *               perform it.
 */
void list_task(void) {
    /* TODO: Complete this function */
}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s\n", progname);
    printf("Run an interactive list manipulation program\n");
    printf("Commands: [i]insert, [r]emove, [p]rint, e[x]it\n");
    printf("  (Commands require an integer argument)\n");
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

    /*
     * parse the command-line options.  For this program, we only support the
     * parameterless 'h' option, for getting help on program usage.
     */
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
          case 'h': help(argv[0]); break;
        }
    }

    /* run the list program */
    list_task();
}
