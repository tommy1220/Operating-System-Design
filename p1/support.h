#ifndef SUPPORT_H__
#define SUPPORT_H__

/*
 * Store information about the student who completed the assignment, to
 * simplify the grading process.  This is just a declaration.  The definition
 * is in student.c.
 */
extern struct student_t {
  char *name;
  char *email;
} student;

/*
 * This function verifies that the student name is filled out
 */
void check_student(char *);

/*
 * A useful constant for dealing with max string lengths.  Note that a
 * 1024-character line needs a trailing \0, so make it 1025 bytes.
 *
 * NB: Don't forget that macros get text-substituted.  Put it in parens to
 *     avoid trouble later.
 */
#define MAX_STR_LEN (1024+1)

#endif
