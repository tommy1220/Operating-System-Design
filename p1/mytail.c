#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "support.h"

/*
 * tail_file() - display the last numlines lines of a file or stdin
 */
void tail_file(char * filename, int numlines) {
  // fgets 的使用方法：char *fgets(char *string, int n, FILE *stream) 

  // 从文件stream中读取n-1个字符/一行（若一行不满n-1个），string接收字符串

  //  如果n <= 0，返回NULL

  //  如果n == 1，返回" "，也就是一个空串

  //  如果成功，返回值等于string， 也就是获得字符串的首地址

  //  如果出错，或者读到FILE的结尾，返回NULL.
  // {
  //  FILE* wordFile = fopen("words.txt","r");
  //  char word[100];

  //  while(fgets(word, 100, wordFile))
  //  {
  //   word[strlen(word)-1] = '/0';
  //   printf("%s is %d characters long/n", word, strlen(word));
  //  }
  //  fclose(wordFile);
  //  return (0);
  // }
  //apple trees=>apple trees is 11 characters long   line len is <100, put onto string

  //   int main(void){ 
  //   int i, row, column, **arr; 

  //   while (scanf("%d %d", &row, &column) != EOF) { 
  //     arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址 
  //     for (i = 0; i < row; i ++) { // 按行分配每一列 
  //       arr[i] = (int *)malloc(sizeof(int) * column);   
  //     } 

  //     free(arr); 
  //   } 

  //   return 0; 
  // } 

  char * * arr; //store strings into 2-dimensional char array
  int i, j, row,num;
  row = numlines;
  FILE * fp;
  num=0;
  //arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址 
  arr = (char * * ) malloc(sizeof(char * ) * row); //assign initial address for all rows
  for (i = 0; i < row; i++) {
    arr[i] = (char * ) malloc(1024 * sizeof(char)); //assign column memory for each row, column is 1024
  }

  if ((fp = fopen(filename, "r")) != NULL) {
    if (fp == NULL) {
      perror("File can't be opened \n");
      exit(-1);
    } 
    else {
      int ln = 0;
      while (fgets(arr[ln], 1024, fp) != NULL) { // ln-> row = 7
        if (ln < row - 1) {
          ln++;
        } 
        else if (ln == row - 1) {
          ln = 0;
        }

      }
      //recurring array repeating from 0-9,suppose numlines =10, and
      //then print backwards
      for (j = 0; j < row; j++) {
        printf("%s", arr[(row + ln - 1 - j) % row]);
        free(arr[(row + ln - 1 - j) % row]);
      }
      free(arr);
    }
  } 
  //stdin
  else if (filename == NULL) {
    // char * line = NULL;

    while(NULL != fgets(arr[num%row], 1024, stdin))
    {
      num++;
    }
  }
  fclose(fp);

}

/*
 * help() - Print a help message.
 */
void help(char * progname) {
  printf("Usage: %s [FILE]\n", progname);
  printf("Print the last 10 lines  of FILE to STDOUT\n");
  printf("With no FILE, read from STDIN\n");
  printf("  -nK    print the last K lines instead of the last 10\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char * * argv) {
  /* for getopt */
  long opt;
  int numlines = 10;
  /* run a student name check */
  check_student(argv[0]);

  /* parse the command-line options.  For this program, we only support  */
  /* the parameterless 'h' option, for getting help on program usage, */
  /* and the parametered 'n' option, for getting the number of lines. */
  while ((opt = getopt(argc, argv, "hn:")) != -1) {
    switch (opt) {
    case 'h':
      help(argv[0]);
      break;
    case 'n':
      numlines = atoi(optarg);
      printf("numlines is: %d",numlines);
      break;
    }
  }

  tail_file(optind < argc ? argv[optind] : NULL, numlines);
}