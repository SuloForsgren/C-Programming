#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int D6_Roll(int low, int high);
int D10_Roll(int low, int high);
void errorHandler(void);

int selection;

int main(void) {
    
    while (1) {
        printf("(1) Roll D6\n(2) Roll D10\n(3) Quit\n ");
        scanf("%d", &selection);

        if (selection == 3) {
            break;
        }
        else if (selection < 1 || selection > 3) {
            errorHandler();
        }
        
        else {
            switch(selection) {
                case 1:
                    int D6_result = D6_Roll(1,6);
                    printf("You rolled %d\n", D6_result);
                    break;
                case 2:
                    int D10_result = D10_Roll(1,10);
                    printf("You rolled %d\n", D10_result);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}

int D6_Roll(int low, int high) {
    srand(time(NULL));
    int number = rand() % (high) + low;
    return number;
}

int D10_Roll(int low, int high) {
    srand(time(NULL));
    int number = rand() % (high) + low;
    return number;
}

void errorHandler(void) {
    printf("There was an error with your selection. Please select again from numbers 1. 2. and 3.\n");
}