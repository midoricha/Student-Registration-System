#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#define MAX_STUDENTS 100
#define MAX_COURSES 50

#include <string.h>
#include <stdio.h>

void display_students(char **students, int num_students);
void display_courses(char **courses, int num_courses);
void register_student(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]);
void drop_student(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]);
void display_enrollment_table(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]);
int find_student_index(char **students, int num_students, char student_id[100]);
int find_course_index(char **courses, int num_courses, char course_code[100]);

#endif