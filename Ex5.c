#include <stdio.h>

int read_range(int low, int high);
int result;

int main(void) {

    printf("%s\n", "Let's play!");
    for (int i = 0; i < 3; i++ ) {
        printf("%s\n", "Roll a die and enter your result.");
        result = read_range(1,6);

        if (result == 6) {
            printf("I got 6. It is a tie!\n");
        }
        else {
            printf("I got %d. I win!\n", result + 1);
        }
    }
    printf("Better luck next time. Bye!");
    return 0;
}

int read_range(int low, int high) {
    int integer;
    while (1) {
        printf("Enter a number between %d and %d: ", low, high);
        scanf("%d", &integer);

        if (integer >= low && integer <= high) {
            break;
        }
        else {
            printf("Error with the entered integer %d. Please enter valid integer\n", integer);
        }
    }
    return integer;
}