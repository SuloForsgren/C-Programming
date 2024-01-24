#include <stdio.h>

int main() {
    int num_students, student_number, grade;
    int index = 0;

    printf("How many students: ");
    scanf("%d", &num_students);

    int grades[num_students];
    for (int i = 0; i < num_students; i++) 
    {
        grades[i] = -1;
    }

    while (1) 
    {
        printf("Enter student number (1 - %d) or 0 to stop: ", num_students);
        scanf("%d", &student_number);

        if (student_number == 0) 
        {
            break;
        } 
        else if (student_number >= 1 && student_number <= num_students) 
        {
            while (1) 
            {
                printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", student_number);
                scanf("%d", &grade);

                if (grade >= -1 && grade <= 5) 
                {
                    grades[student_number - 1] = grade;
                    break;
                } 
                else 
                {
                    printf("Invalid grade!\n");
                }
            }
            
        } 
        else 
        {
            printf("Invalid student number!\n");
        }
    }

    printf("%s%8s\n", "Student", "Grade");

    while (index < num_students)
    {
        if (grades[index] == -1) 
        {
            printf("%d%12s\n", index + 1, "N/A");
        }            
        else 
        {
            printf("%d%10d\n", index + 1, grades[index]);
        }
        index++;
    }        

    return 0;
}
