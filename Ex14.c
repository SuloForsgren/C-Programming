#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 80

int main(void) {
    FILE *my_file;
    char lines[MAX_LINES][MAX_LENGTH + 1];
    char filename[MAX_LENGTH];
    int line_count = 0;
    char *filename_extension = ".txt";

    printf("Please enter a file name: ");
    scanf("%s", filename);

    strcat(filename, filename_extension);

    my_file = fopen(filename, "r");

    if (my_file != NULL) {
        printf("File opened\n");

        while (fgets(lines[line_count], MAX_LENGTH, my_file) != NULL && line_count < MAX_LINES) {
            line_count++;
        }

        fclose(my_file);

        for (int i = 0; i < line_count; i++) {
            for (int j = 0; lines[i][j] != '\0'; j++) {
                lines[i][j] = toupper(lines[i][j]);
            }
        }

        my_file = fopen(filename, "w");

        if (my_file != NULL) {
            for (int i = 0; i < line_count; i++) {
                fputs(lines[i], my_file);
            }
            fclose(my_file);
            printf("File successfully processed and written.\n");
        } 
        else {
            fprintf(stderr, "Error opening file %s for writing.\n", filename);
            exit(1);
        }
    } 
    else {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    return 0;
}
