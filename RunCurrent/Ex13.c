    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define Length 80

    int main(void) {
        FILE *my_file;
        int count = 0;
        int value = 0;
        char filename[Length];
        char line[Length];
        
        printf("Please enter a file name: ");
        scanf("%s", filename);

        strcat(filename, ".txt");
        my_file = fopen(filename, "r");

        if (my_file != NULL) {
            printf("File opened\n");

            while (!feof(my_file)) {
                if (fgets(line, Length, my_file) != NULL) {
                    if (sscanf(line, "%d", &value) == 1) {
                        count++;
                    }
                    else {
                        break;
                    }
                }
            }
            printf("Integer count: %d", count);
        }
        else {
            print("Couldn't open file %s", filename);
            exit(0);
        }

        return 0;
    }