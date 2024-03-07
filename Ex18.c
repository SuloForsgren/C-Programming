#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HIGHEST 10

int main(void) {
    time_t t;
    srand((unsigned) time(&t));
    char input[HIGHEST];
    int integer, randomize;

    while(1) {
        printf("Please enter an integer: ");
        scanf("%d", &integer);
        if (integer >= 0 && integer <= 15) {
            randomize = rand();
            printf("%x\n", randomize);

            randomize >>= integer;
            randomize &= 0x3F;

            printf("Result in hexadecimal with two digits and leading zeros: 0x%02X\n", randomize);
        }
        else if (integer < 0) {
            break;
        }
    }

    return 0;
}