#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int calculate_checksum(const char *sentence) {
    int checksum = 0;
    for (int i = 1; sentence[i] != '*' && sentence[i] != '\0'; i++) {
        checksum ^= sentence[i];
    }
    return checksum;
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (line[0] == '$') {
            char *checksum_position = strchr(line, '*');
            if (checksum_position != NULL) {
                int received_checksum;
                if (sscanf(checksum_position + 1, "%x", &received_checksum) == 1) {
                    int calculated_checksum = calculate_checksum(line);
                    if (calculated_checksum == received_checksum) {
                        printf("[ OK ] %s", line);
                    } else {
                        printf("[FAIL] %s", line);
                    }
                } else {
                    printf("[FAIL] %s", line);
                }
            } else {
                printf("[FAIL] %s", line);
            }
        }
    }

    fclose(file);
    return 0;
}