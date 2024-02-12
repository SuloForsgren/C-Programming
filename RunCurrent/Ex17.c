#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define passwordLength 32
#define ARRLength 30

int array[ARRLength]

bool generatePassword(int passwordLen, const char *word) {
    for (int i = 2; i < passwordLen + 2; i++) {
        if (i % 2 == 0) {
            array[i] = word[i]
        }
        else {
            array[i] = 
        }
    }


    return false;
}


int main(void) {
    char password[passwordLength];
    int ARRlength;

    while(1) {
        printf("Enter a password: ");
        scanf("%s", &password);

        if(strcmp(password, "stop") == 0) {
            break;
        }
        else {
            ARRlength = (strlen(password) * 2 + 1);
            generatePassword(ARRlength, password);
        }
    }

    return 0;
}