#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

char first[MAX_LENGTH];
char search[MAX_LENGTH];

int count_words(const char *defaultString, const char *search) {
    int count = 0;
    int search_length = strlen(search);

    while ((defaultString = strstr(defaultString, search)) != NULL) {
        count++;
        defaultString += search_length;
    }

    return count;
}

int main(void) {
    printf("Please enter a string: ");
    fgets(first, MAX_LENGTH, stdin);
    first[strcspn(first, "\n")] = '\0'; // Remove newline character if needed

    printf("Please enter a word to search for: ");
    fgets(search, MAX_LENGTH, stdin);
    search[strcspn(search, "\n")] = '\0';

    int count = count_words(first, search);

    printf("%d", count);

    return 0;
}
