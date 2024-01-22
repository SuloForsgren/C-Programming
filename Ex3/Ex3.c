#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int students;
    int student;
    int grade;
    int index = 0;  // Initialize index to 0
    char buf[20];  // Adjust the size according to your needs

    printf("How many students: ");
    scanf("%d", &students);

    if (students <= 0) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;  // Exit with an error code
    }

    int *studentArray = (int *)malloc(students * sizeof(int));

    while (1) {
        printf("Enter student number (1 - %d) or 0 to stop: ", students);
        scanf("%d", &student);

        if (student == 0) {
            break;
        }

        if (student > students || student < 1) {
            printf("Invalid student number!\n");
        } else {
            printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", student);
            scanf("%d", &grade);

            if (grade > 5 || grade < -1) {
                printf("Invalid grade!\n");
            } else {
                studentArray[index] = (grade == -1) ? -1 : grade;
                index++;
            }
        }
    }

    printf("\n%-10s%10s\n", "Student", "Grade");

    for (int i = 0; i < index; i++) {
        printf("%-10d%10s\n", i + 1, (studentArray[i] == -1) ? "N/A" : (sprintf(buf, "%d", studentArray[i]), buf));
    }

    free(studentArray); // Free the allocated memory

    return 0;
}