#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 32
#define ARRAY_LENGTH 64

char array[ARRAY_LENGTH];

bool generatePassword(char *password, int size, const char *word) {
    int wordLen = strlen(word);
    int passwordLen = wordLen * 2 + 1;

    if (passwordLen > size) {
        return false;
    }

    password[0] = rand() % (126 - 33 + 1) + 33;

    for (int i = 0; i < wordLen; i++) {
        password[i * 2 + 1] = word[i];
        password[i * 2 + 2] = rand() % (126 - 33 + 1) + 33;
    }

    password[passwordLen - 1] = rand() % (126 - 33 + 1) + 33;
    password[passwordLen] = '\0';

    return true;
}


int main() {
    srand(time(NULL));
    char word[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH * 2 + 1];

    while (1) {
        printf("Enter a word (or 'stop' to stop the program): ");
        scanf("%s", word);

        if (strcmp(word, "stop") == 0) {
            break;
        } else {
            if (generatePassword(password, sizeof(password), word)) {
                printf("Generated password: %s\n", password);
            } else {
                printf("Error: Password could not be generated. The word is too long.\n");
            }
        }
    }

    return 0;
}