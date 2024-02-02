#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what) {

    for (int i = 0; i < 19; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}

int numberArray[20];
int input;

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 18; i++) {
        numberArray[i] = rand() % (20) + 1;
    }
    numberArray[19] == 0;

    for (int i = 0; i < 19; i++) {
        printf("%d\n", numberArray[i]);
    }

    do {
        printf("Enter a number to search for or zero to stop the program.\n");
        printf(":>>");
        scanf("%d", &input);
        if (input < 0) {
            printf("Not found!\n");
        }

        else if (input > 0) {
            int result = find_first(numberArray, input);
            
            if (result == -1) {
                printf("Not found!\n");
            }
            else {
                printf("%d\n", result);
            }
            
        }

    } while(input != 0);

    return 0;
}