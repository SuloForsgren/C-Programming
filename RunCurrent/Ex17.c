#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 32
#define ARRAY_LENGTH 64 // Adjusted to accommodate the length of the password and random characters

char array[ARRAY_LENGTH];

bool generatePassword(int passwordLen, const char *word) {
    for (int i = 1; i < passwordLen - 1; i += 2) {
        array[i] = word[(i - 1) / 2]; // Inserting characters from the word
        array[i + 1] = rand() % (126 - 33 + 1) + 33; // Inserting random characters
    }
    array[0] = rand() % (126 - 33 + 1) + 33; // Starting random character
    array[passwordLen - 1] = rand() % (126 - 33 + 1) + 33; // Ending random character
    array[passwordLen] = '\0'; // Null terminator

    printf("%s\n", array);
    return false;
}


int main(void) {
    char password[PASSWORD_LENGTH];
    int ARRlength;

    while(1) {
        printf("Enter a password: ");
        scanf("%s", &password);

        if(strcmp(password, "stop") == 0) {
            break;
        }
        else {
            generatePassword(strlen(password) * 2 + 2, password);
        }
    }

    return 0;
}