#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    int number;
    printf("Enter a positive number: ");
    
    if (scanf("%d", &number) == 1 && number >= 0) {
        *value = number;
        return true;
    } 
    else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
}

int main(void) {
    int wrong_input = 0;
    int number;
    do {
        
        printf("Guess how much money I have!\n");

        if (read_positive(&number)) {
            printf("You didn't get it right. I have %d euros. \n", 2 * number + 20);
        } 
        else {
            printf("Incorrect input\n");
            wrong_input++;
        }
    } while (wrong_input < 3);
    printf("I give up! See you later!\n");

    return 0;
}

