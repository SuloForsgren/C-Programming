#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Length 80

int main(void) {
    FILE *my_file;
    int count = 0;
    int value = 0;
    int lowest;
    int highest;
    char filename[Length];
    char line[Length];
    
    printf("Please enter a file name: ");
    scanf("%s", filename);

    strcat(filename, ".txt");
    my_file = fopen(filename, "r");

    if (my_file != NULL) {
        printf("File opened\n");

        while (fgets(line, Length, my_file) != NULL) {
            if (sscanf(line, "%d", &value) == 1) {
                count++;

                if (lowest > value) {
                    lowest = value;
                }
                if (highest < value) {
                    highest = value;
                }
            }
            else {
                break;
            }
        }

        printf("Integer count: %d\nLowest value found: %d\nHighest value found: %d\n", count, lowest, highest);
        fclose(my_file);
    }
    else {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        exit(1);
    }

    return 0;
}
