/*
 * Title : Assignment #1 - Student Registration System
 * Course : CST8234 C Language
 * @Author : <<<Danyu Wan(041060144)>>>
 * Lab Section : 012
 * Professor : Surbhi Bahri
 * Due date : 03 / 11 / 23
 * Submission date : 03 / 11 / 23
 *
 *
 *
 * Demo malloc(), memset(), calloc() and free() in C, Ansi-style
 * Status:
 * Requirement #1: {Complete}
 * Requirement #2: {Complete}
 * Requirement #3: {Complete}
 * Requirement #4: {Complete}
 * Requirement #5: {Complete}
 * Requirement #6: {Complete}
 * Requirement #7: {Complete}
 * Requirement #8: {Complete}
 * Requirement #9: {Complete}
 */

/*****************************************************************************
Function Name: main
Purpose: abjkndx,asm c.a
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/

#include "defs.h"
#include "course.h"
#include "student.h"
#include "enrollment.h"

/*****************************************************************************
Function Name: main
Purpose: main function for program execution
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int num_students, num_courses;

    printf("Welcome to Student Registration System.\n");

    printf("Enter the number of students to register: ");
    scanf("%d", &num_students);

    char **students = (char **)malloc(num_students * sizeof(char *));

    register_students(students, num_students);

    printf("Enter the number of courses available: ");
    scanf("%d", &num_courses);

    // double pointer,amtCourse, contains char *.Directs us to 2 points of memory.Using double pointer to get words and not single characters.
    char **courses = (char **)malloc(num_courses * sizeof(char *)); 

    register_courses(courses, num_courses);

    int **enrollments = calloc(num_students, sizeof(int *));
    for (int i = 0; i < num_students; i++)
    {
        enrollments[i] = calloc(num_courses, sizeof(int));
    }

    int choice;

    do
    {
        printf("Main Menu:\n[1] Register a student into a course\n[2] Drop a student from a course\n[3] Display registration table\n[4] Exit\nEnter an option: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case REGISTER_STUDENT:
            register_student(students, num_students, courses, num_courses, enrollments);
            break;
        case DROP_STUDENT:
            drop_student(students, num_students, courses, num_courses, enrollments);
            break;
        case DISPLAY_TABLE:
            display_enrollment_table(students, num_students, courses, num_courses, enrollments);
            break;
        case EXIT:
            printf("Exiting...\n");
            printf("Program by Danyu Wan\n");

            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 - 5.\n");
            break;
        }
    } while (choice != EXIT);

    free(students);
    free(courses);
    for (int i = 0; i < num_students; i++)
    {
        free(enrollments[i]);
    }
    free(enrollments);

    return 0;
}