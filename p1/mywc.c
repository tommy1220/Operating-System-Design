#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "support.h"

/*
 * wc_file() - count characters, words, and lines
 */
void wc_file(char *filename) {
    /* TODO: Complete this function */
    //if(strlen(filename)>0)
    FILE *fp;
    char ch;
    int read=0;
    int charCount =0;
    int wordCount = 0;
    int lineCount = 0;
    if((fp=fopen(filename,"r"))==NULL){
    perror("No document is found to count word \n");
    exit(1);
    }
    else {
     ch=fgetc(fp);
     while(EOF!=ch)
     {
     charCount++;
     read++;
     if((ch>=48 && ch<=57)||(ch>=65 && ch<=90)||(ch>=97 && ch<=122))
       {
         read++;
       }
     //special chars
     if(ch=='.'|| ch==',' || ch=='?' || ch==':' || ch=='"' ||
        ch==';'||ch=='_'||ch=='_'||ch=='`')
     {
        charCount++;
        read++;
        ch=fgetc(fp);
     }
     if(ch=='\t' || ch=='\n' || ch==' ' )
       {
         if(ch=='\n')
           {
            lineCount++;
           }
         if(read!=0){
            read=0;
            wordCount++;
           }
       }
       ch=fgetc(fp);
       }
     printf("%d   %d   %d   %s \n", lineCount, wordCount, charCount, filename);
     fclose(fp);
    }
}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s [FILE]\n", progname);
    printf("Print newline, word, and byte counts for FILE\n");
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

    /* error if we don't have a file, else call wc_file */
    if (argc != 2) {
        printf("Error: no file given\n");
        exit(1);
    }
    wc_file(argv[1]);
}

