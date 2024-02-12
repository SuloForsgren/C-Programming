#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define read_length 15

typedef struct node {
 int number;
 struct node *next;
} nnode;

int main(void) {

    char input[read_length];
    int value = 0;

    while(1) {
        printf("Enter a number or 'end': ");
        fgets(input, read_length, stdin);
        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "%d", &value) == 1) {
            printf("You entered an integer!\n");
        }

        else if (strcmp(input, "end") == 0) {
            printf("Ending!\n");
            break;
        }
        
        else {
            printf("Error\n");
        }
    }
    
    return 0;
}