#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "support.h"
#include <stdbool.h> 
#define MAX_SIZE 1000000
#define MAX_WORDS 1024

/*
 * sort_file() - read a file, sort its arr, and output them.  reverse and
 *               unique parameters are booleans to affect how the arr are
 *               sorted, and which arr are output.
 */




void moveLine(int linePtr, char * * arr, int rowNum) {
  for (int i = linePtr; i < rowNum; i++) {
    arr[i - 1] = arr[i];
  }

}



//for qsort
int myCmp(const void * line1,
  const void * line2) {
  char * line_1 = * (char * * ) line1;
  char * line_2 = * (char * * ) line2;
  return strcmp(line_1, line_2);
}


void sort_file(char * filename, int u, int r) {
  /* TODO: Complete this function */
  /* Note: you will probably need to implement some other functions */

  //  int ** arr;
  //     arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址 
  //     for (i = 0; i < row; i ++) { // 按行分配每一列 
  //       arr[i] = (int *)malloc(sizeof(int) * column);   
  // arr = (char * * ) malloc(sizeof(char * ) * row); //assign initial address for all rows
  // for (i = 0; i < row; i++) {
  //   arr[i] = (char * ) malloc(MAX_WORDS * sizeof(char)); //assign column memory for each row, column is MAX_WORDS
  // }
  FILE * fp;
  char * * arr;
  int row = 0;
  //arr=(char * * ) malloc(sizeof(char * ) * MAX_SIZE);

  if ((fp = fopen(filename, "r")) != NULL) {
    

      arr = malloc(MAX_SIZE * sizeof(char * ));
      arr[row] = (char * ) malloc(MAX_WORDS * sizeof(char));

      while (fgets(arr[row], MAX_WORDS, fp) != NULL) {
        row++;
        arr[row] = (char * ) malloc(MAX_WORDS * sizeof(char));
      }
      free(arr[row]);

      //sorting by C embedded sorting func
      qsort(arr, row, sizeof(char * ), myCmp);

      if (u) {
        for (int i = 1; i < row; i++) {
          if (strcmp(arr[i], arr[i - 1]) == 0) {
            free(arr[i - 1]);
            moveLine(i, arr, row);
            row--;
            i--;
          }
        }
      }
      
		
	  if(r){
	  	  for (int k = row-1; k >=0; k--) {
          printf("%s", arr[k]);
          free(arr[k]);
          }
	  }
	  else{
	  	
        for (int k = 0; k < row; k++) {
          printf("%s", arr[k]);
          free(arr[k]);
        }
      }
      free(arr);
    
    fclose(fp);
  }
  else
  {
  	perror( "File can't be opened \n" );
  	exit(-1);
  }
}

/*
 * help() - Print a help message.
 */

void help(char * progname) {
  printf("Usage: %s [OPTIONS] FILE\n", progname);
  printf("Sort the arr of FILE and print them to STDOUT\n");
  printf("  -r    sort in reverse\n");
  printf("  -u    only print unique arr\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */

int main(int argc, char * * argv) {
  /* for getopt */
  long opt;
  int r,u;
  r=0;
  u=0;
  /* ensure the student name is filled out */
  check_student(argv[0]);

  /* parse the command-line options.  They are 'r' for reversing the */
  /* output, and 'u' for only printing unique strings.  'h' is also */
  /* supported. */
  /* TODO: parse the arguments correctly */

  while ((opt = getopt(argc, argv, "hru")) != -1) {
    switch (opt) {
    case 'h':
      help(argv[0]);
      break;
    case 'r':
      r = 1;
      break;
    case 'u':
      u = 1;
      break;
    }
  }

  /* TODO: fix this invocation */
  // sort_file(argv[optind], 0, 0);
  sort_file(argv[optind], u, r);
}