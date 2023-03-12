#include "course.h"

/*****************************************************************************
Function Name: register_courses
Purpose: register course ID, validate and store in an array
Function in parameters: char **courses, int num_courses
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void register_courses(char **courses, int num_courses)
{
    for (int i = 0; i < num_courses; i++)
    {
        courses[i] = (char *)malloc(100 * sizeof(char));

        if (courses == NULL)
        {
            printf("Cannot allocate memory to courses\n");
            return;
        }

        printf("Enter the course index [%d] course ID [3-alphas][4-digits]: ", i);
        scanf("%s", courses[i]);

        char course_code[100];
        strcpy(course_code, courses[i]);
        bool digitCheck = true;

        for (int j = 0; j < 3; j++)
        {
            if (!isalpha(course_code[j]))
            {
                digitCheck = false;
            }
        }
        for (int j = 3; j < 7; j++)
        {
            if (!isdigit(course_code[j]))
            {
                digitCheck = false;
            }
        }

        if (strlen(courses[i]) != 7 || !digitCheck)
        {
            printf("Incorrect course code input [3-alphas][4-digits]\n");
            i--; // to move back one step if error occurs.
        }
    }
    printf("Courses are: ");
    for (int i = 0; i < num_courses; i++)
    {
        printf("%s ", courses[i]);
    }
    printf("\n");
}
