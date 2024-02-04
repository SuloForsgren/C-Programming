#include <stdio.h>
#include <stdlib.h>

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}

int main(void) {
    int numberArray[15];
    int arraysize;

    for (int i = 0; i < 15; i++) {
        numberArray[i] = rand();
    }

    arraysize = sizeof(numberArray) / sizeof(numberArray[0]);
    print_numbers(numberArray, arraysize);

    return 0;
}