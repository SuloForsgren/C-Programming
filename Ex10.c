#include <stdio.h>
#include <string.h>

int main() {
    char input[50];

    while (1) {
        printf("Enter a line of text: ");
        fgets(input, sizeof(input), stdin);

        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
            length = strlen(input);
        }

        printf("String length: %d\n", length);
        
        if (strcmp(input, "stop") == 0) {
            break;
        }
    }

    return 0;
}