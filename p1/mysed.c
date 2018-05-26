#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

/*
 * sed_file() - modify lines of filename based on pattern, and print result
 *              to STDOUT
 */


int isPatternValid(char * pattern, char * zzz, char * yyy)
{
	char *token = NULL;
	token = strtok(pattern, "/");  
    char *begin = token;
    char str1[]="s";
    if(strcmp(begin,str1)!=0)
    	return -1;
    token = strtok(NULL, "/");  
    if(token==NULL||strcmp(token,"")==0)
    {
    	printf("find error/n");
    	return -1;
    }
    strcpy(zzz,token);
    token = strtok(NULL, "/");  
    if(token==NULL)
    {
    	return -1;
    }
    strcpy(yyy,token);
    token = strtok(NULL, "/");  
    if(token==NULL&&strcmp(yyy,"g")==0)
    {
    	strcpy(yyy,"");
    	return 0;
    }
    if(token==NULL||strcmp(token,"g")!=0)
    {
    	return -1;
    }
    return 0;
}

void sed_file(char *filename, char *pattern) {
    /* TODO: Complete this function */
    FILE * fp;
	char zzz [1024], yyy [1024];
	int valid = isPatternValid(pattern, zzz, yyy);
	if(valid<0){
		perror("pattern is not valid");
		exit(1);
	}


  if ((fp = fopen(filename, "r")) != NULL) {
    if (fp == NULL) {
      perror("File can't be opened \n");
      exit(-1);
    } 
    else{
    printf("original key word is :  %s\nreplacing with :  %s\n", zzz, yyy);
    // while(fgets(line, 2048, fp) != NULL){
    //     char newstr [2048];
    //     char *p;
    //     strcpy(newstr,line);
    //     // char s[] = "strrrrrrrZZZrrrrrrrrZZZrrrrr";  
    //     //
    //         strncpy(newstr, line, p-line);
    //         char *str=strtok(newstr,zzz);
    //         str=str+yyy;
    //         while(str!=NULL){

    //         }


    //         if(strcmp(newstr,line)!=0)
    //         {
    //             strcpy(line,newstr);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //    // }
    //     printf("%s", newstr);
    // }
    }


  }

    else if (filename == NULL) {
        fp=stdin;
  }
    if(pattern == NULL){
    perror("No Pattern Found");
    exit(1);
    }


    // char *oldline;
    // oldline = (char*) malloc(sizeof(char)*1024);
    // while(fgets(oldline,2048,fp)!=NULL){
    //     char *newline;
    //     newline = (char*) malloc(sizeof(char)*1024);
    //     strcpy(newline,oldline);
    //     while(strstr=(oldline,zzz)!=NULL){
    //         strncpy()
    //     }
    // }


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
    check_student(argv[0]);

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
