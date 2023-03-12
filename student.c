#include "student.h"

/*****************************************************************************
Function Name: register_students
Purpose: register student ID, validate and store in an array
Function in parameters: char **students, int num_students
Function out parameter: void
Version: 1
Author: Danyu Wan
*****************************************************************************
/
*/
void register_students(char **students, int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        students[i] = (char *)malloc(100 * sizeof(char));

        if (students == NULL)
        {
            printf("Cannot allocate memory to students\n");
            return;
        }

        printf("Enter the student index [%d] student ID [5 digits]: ", i);
        scanf("%s", students[i]);

        int len = strlen(students[i]);
        char student_id[100];
        int isDigit = 1;

        strcpy(student_id, students[i]);

        for (int i = 0; student_id[i] != '\0'; i++)
        {
            if (!isdigit(student_id[i]))
            {
                isDigit = 0;
            }
        }

        if (len != 5 || isDigit == 0)
        {
            printf("Student ID must be a 5 digit number\n");
            i--;
        }

        if (len > 1 && student_id[0] == '0')
        {
            for (int j = 0; j < len - 1; j++)
            {
                student_id[j] = student_id[j + 1];
            }
            len--;
        }
    }

    printf("Students are: ");
    for (int i = 0; i < num_students; i++)
    {
        printf("%s ", students[i]);
    }
    printf("\n");
}
