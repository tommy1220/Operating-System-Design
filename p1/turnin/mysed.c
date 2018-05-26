#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

/*
 * sed_file() - modify lines of filename based on pattern, and print result
 *              to STDOUT
 */

 int check_pattern(const char * pattern, char * find, char * replace_with){
  int char_pointer = 0;
  if(pattern[char_pointer] == '\0' || pattern[char_pointer] != 's')
    return 0;
  char_pointer++;
  if(pattern[char_pointer] == '\0' || pattern[char_pointer] != '/')
    return 0;
  char_pointer++;
  int start = char_pointer;
  while(pattern[char_pointer] != '\0' && pattern[char_pointer] != '/'){
    find[char_pointer-start] = pattern[char_pointer];
    char_pointer++;
  }
  find[char_pointer-start]='\0';
  if(pattern[char_pointer] == '\0')
    return 0;
  char_pointer++;
  start = char_pointer;
  while(pattern[char_pointer] != '\0' && pattern[char_pointer] != '/'){
    replace_with[char_pointer-start] = pattern[char_pointer];
    char_pointer++;
  }
  replace_with[char_pointer-start]='\0';
  if(pattern[char_pointer] == '\0')
    return 0;
  char_pointer++;
  if(pattern[char_pointer] == '\0' || pattern[char_pointer] != 'g')
    return 0;
  char_pointer++;
  if(pattern[char_pointer] == '\0')
    return 1;
  return 0;
}

void replace_str(char *str, char *newstr, char *find, char *replace){
  char *p;
  if(!(p = strstr(str, find))){
    strcpy(newstr, str);
    return;
  }
  strncpy(newstr, str, p-str);
  newstr[p-str] = '\0';
  sprintf(newstr+(p-str), "%s%s", replace, p+strlen(find));
}

void sed_file(char *filename, char *pattern) {
    /* TODO: Complete this function */
    if(pattern == NULL){
    printf("Please enter pattern");
    exit(1);
  }
  char find [1024], replace_with [1024];
  int valid = check_pattern(pattern, find, replace_with);
  if(!valid){
    printf("Error: Pattern is not formatted correctly");
    exit(1);
  }

  FILE * fp;
  if(filename == NULL){
    fp = stdin;
  }else{
    fp = fopen(filename, "r");
  }
  if(fp == NULL){
    printf("Error: File could not be opened");
    exit(1);
  }

  char line [2048];
  while(fgets(line, 2048, fp) != NULL){
    char newstr [2048];
    replace_str(line, newstr, find, replace_with);
    while(0 != strcmp(newstr, line)){
      strcpy(line, newstr);
      replace_str(line, newstr, find, replace_with);
    }
    printf("%s", newstr);
  }
  fclose(fp);
}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s [FILE]\n", progname);
    printf("Print the contents of FILE to STDOUT\n");
    printf("With no FILE, read standard input\n");
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

    /* TODO: fix this invocation */
    sed_file(argv[2], argv[1]);
}
