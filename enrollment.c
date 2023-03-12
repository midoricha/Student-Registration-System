#include "student.h"
#include "course.h"
#include "enrollment.h"

int registration_index = 0;
char status;

/*****************************************************************************
Function Name: register_student
Purpose: register a student to a course
Function in parameters: char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void register_student(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses])
{
    char student_id[100];
    char course_code[100];
    int student_index, course_index;

    display_students(students, num_students);
    printf("Enter the student's ID to register a course: ");
    scanf("%s", student_id);

    student_index = find_student_index(students, num_students, student_id);

    while (student_index == -1)
    {
        printf("\nStudent with ID %s not found. Please enter a valid ID: ", student_id);
        scanf("%s", student_id);
        student_index = find_student_index(students, num_students, student_id);
    }

    display_courses(courses, num_courses);
    printf("Enter the course ID [3-Alphas][4-Digits]: ");
    scanf("%s", course_code);

    course_index = find_course_index(courses, num_courses, course_code);

    while (course_index == -1)
    {
        printf("\nCourse with ID %s not found. Please enter a valid ID: ", course_code);
        scanf("%s", course_code);
        course_index = find_course_index(courses, num_courses, course_code);
    }

    if (enrollments[student_index][course_index] == 1)
    {
        printf("Already on record.\nStudent %s cannot register to course %s.\n", students[student_index], courses[course_index]);
        printf("Registration unsuccessful\n");
    }
    else if (enrollments[student_index][course_index] == 2)
    {
        printf("Student id %s has dropped out from course %s, cannot register.\n", students[student_index], courses[course_index]);
    }
    else
    {
        enrollments[student_index][course_index] = 1;
        printf("\nRegistration successful\n");
        registration_index++;
    }
}

/*****************************************************************************
Function Name: drop_student
Purpose: drop a student to a course
Function in parameters: char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void drop_student(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses])
{
    int reg_index;
    char course_code[100];
    int student_index, course_index;

    // Check if there are any courses to drop
    int has_courses_to_drop = 0;
    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < num_courses; j++)
        {
            if (enrollments[i][j] == 1)
            {
                has_courses_to_drop = 1;
                break;
            }
        }
    }

    if (!has_courses_to_drop)
    {
        printf("There are no courses to drop.\n");
        return;
    }

    display_enrollment_table(students, num_students, courses, num_courses, enrollments);

    printf("\nPlease select index number to drop student registration: ");
    scanf("%d", &reg_index);

    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < num_courses; j++)
        {
            if (j == reg_index)
            {
                if (enrollments[i][j] == 1)
                {
                    printf("Drop course successful\n");
                    enrollments[i][j] = 2;
                }
                else if (enrollments[i][j] == 2)
                {
                    printf("Unsuccessful. Please enter a valid index number.\n");
                    return;
                }
            }
        }
    }
    display_enrollment_table(students, num_students, courses, num_courses, enrollments);
}

/*****************************************************************************
Function Name: display_enrollment_table
Purpose: display the enrollment table
Function in parameters: char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses]
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void display_enrollment_table(char **students, int num_students, char **courses, int num_courses, int enrollments[][num_courses])
{
    int i, j, reg_index = 0;

    printf("\t\t\t\tRegistration Table\t\t\t\t\n");
    printf("Registration Index\tStudent ID\tCourse ID\tRegistration Status\n");
    for (i = 0; i < num_students; i++)
    {
        for (j = 0; j < num_courses; j++)
        {
            if (enrollments[i][j] == 1)
            {
                status = 'R';
                printf("\t%d\t\t%s\t\t%s\t\t\t%c\n", reg_index++, students[i], courses[j], status);
            }
            if (enrollments[i][j] == 2)
            {
                status = 'D';
                printf("\t%d\t\t%s\t\t%s\t\t\t%c\n", reg_index++, students[i], courses[j], status);
            }
        }
    }
}

/*****************************************************************************
Function Name: display_students
Purpose: display the students array storing student IDs
Function in parameters: char **students, int num_students
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void display_students(char **students, int num_students)
{
    int i;
    printf("List of Student IDs\n");
    for (i = 0; i < num_students; i++)
    {
        printf("Index %d          %s\n", i, students[i]);
    }
}

/*****************************************************************************
Function Name: display_courses
Purpose: display the courses array storing course IDs
Function in parameters: char **courses, int num_courses
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void display_courses(char **courses, int num_courses)
{
    int i;
    printf("List of Available Course IDs\n");
    for (i = 0; i < num_courses; i++)
    {
        printf("Index %d          %s\n", i, courses[i]);
    }
}

/*****************************************************************************
Function Name: find_student_index
Purpose: find student ID index
Function in parameters: char **students, int num_students, char student_id[100]
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
int find_student_index(char **students, int num_students, char student_id[100])
{
    int i;
    for (i = 0; i < num_students; i++)
    {
        if (strcmp(students[i], student_id) == 0)
        {
            return i; // return index of matching student
        }
    }
    return -1; // student with given ID not found
}

/*****************************************************************************
Function Name: find_course_index
Purpose: find course ID index
Function in parameters: char **courses, int num_courses, char course_code[100]
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
int find_course_index(char **courses, int num_courses, char course_code[100])
{
    int i;
    for (i = 0; i < num_courses; i++)
    {
        if (strcmp(courses[i], course_code) == 0)
        {
            return i; // return index of matching course
        }
    }
    return -1; // course with given code not found
}