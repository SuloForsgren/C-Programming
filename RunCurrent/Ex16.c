#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define read_length 15

int main(void) {

    char input[read_length];

    while(1) {
        printf("Enter a number or 'end': ");
        fgets(input, read_length, stdin);

        if (input == "end") {
            printf("Ending!");
            break;
        }
        else if (atof(input) == 0) {
            printf("You entered an integer!");
        }
        else {
            printf("Error");
        }
    }
    
    return 0;
}