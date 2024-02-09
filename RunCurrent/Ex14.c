#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 80
#define LINE_MAX_LENGTH 100

int main(void) {
    FILE *my_file;
    int count = 0;
    int value = 0;
    char filename[MAX_LENGTH];
    char line[LINE_MAX_LENGTH];
    
    printf("Please enter a file name: ");
    scanf("%s", filename);

    strcat(filename, ".txt");
    my_file = fopen(filename, "r");

    if (my_file != NULL) {
        printf("File opened\n");

        while (fgets(line, MAX_LENGTH, my_file) != NULL) {
            if (sscanf(line, "%d", &value) == 1) {
                count++;

            }
            else {
                break;
            }
        }

        printf("Integer count: %d", count);
        fclose(my_file);
    }
    else {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        exit(1);
    }

    return 0;
}
