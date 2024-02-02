#include <stdio.h>
#include <string.h>

char first[80];
char second[2];


int replace_char(const char *defaultString, char *modifyString) {
    char modified[80];
    for (int i = 0; i < strlen(defaultString); i++) {
        if (defaultString[i] == modifyString[0]) {
            modified[i] = modifyString[1];
        }
    }

    printf("%s", modified);

    return 0;
}


int main(void) {
    printf("Please enter the first string: ");
    scanf("%s", first);

    printf("Please enter the second string: ");
    scanf("%s", second);

    replace_char(first, second);
    return 0;
}