#include <stdio.h>

int read_integer(void);

int result, integer;
int numbers = 0;
float sum = 0;

int main(void) {
    while (1) {
        printf("Enter positive numbers or negative to stop: ");
        scanf("%d", &integer);

        if (integer > 0) {
            read_integer();
        }
        else if (integer < 0) {
            sum /= numbers;
            printf("%.3f", sum);
            break;
        }
    }
    return 0;
}

int read_integer(void) {
    sum += integer;
    numbers++;
}