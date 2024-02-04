#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

char first[MAX_LENGTH];
char second[2];

int replace_char(char *defaultString, const char *modifyString) {
    int replaced = 0;

    if (strlen(modifyString) != 2) {
        replaced = 0;
    } 
    else {
        for (int i = 0; i < strlen(defaultString); i++) {
            if (defaultString[i] == modifyString[0]) {
                defaultString[i] = modifyString[1];
                replaced++;
            }
        }
    }

    return replaced;
}

int main(void) {
    printf("Please enter the first string: ");
    fgets(first, MAX_LENGTH, stdin);
    first[strcspn(first, "\n")] = '\0';

    printf("Please enter the second string: ");
    scanf("%s", second);

    int count = replace_char(first, second);
    if (count > 0) {
        printf("The program replaced %d characters.\n", count);
        printf("Modified string: %s\n", first);
    } 
    else {
        printf("String was not modified\n");
    }

    return 0;
}