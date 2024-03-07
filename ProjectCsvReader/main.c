#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define roomLength 30
#define bufferLength 100
#define maxOccurances 20

float split(char buffer[]) {
    char *token = strtok(buffer, ",");
    float num = atof(token);
    return num;
}

bool errorCheck(char input[]) {
    FILE *filePtr;
    char buffer[bufferLength];
    bool roomFound = false;

    filePtr = fopen("data.csv", "r");
    if (filePtr == NULL) {
        printf("Unable to open data.csv\n");
        return false; // Return false if unable to open the file
    }

    // Skip the first line if necessary
    fgets(buffer, bufferLength, filePtr);

    // Read room names from the CSV file and compare with the input
    while (fgets(buffer, bufferLength, filePtr) != NULL) {
        char token[roomLength];
        sscanf(buffer, "%[^,]", token); // Read the room name from the line

        if (strcmp(token, input) == 0) {
            roomFound = true;
            break;
        }
    }

    fclose(filePtr);

    return roomFound;
}

int main(void) {
    FILE *filePtr;
    char buffer[bufferLength];
    int first_row = 1;
    int arrayForTemps[maxOccurances];
    

    filePtr = fopen("data.csv", "r");

    if (filePtr != NULL) {
        while (fgets(buffer, bufferLength, filePtr) != NULL) {
            char input[roomLength];
            if (first_row) {
                first_row = 0;
                continue;
            }

            printf("Please enter the name of the room which you would like to get temperature data from (Bedroom, Kitchen etc..) with a capital letter\n");
            printf(">>");
            scanf("%s", input);
            if (errorCheck) {
                printf("Error! No room with name %s\n", input);
            }
            else {
                float temp = split(buffer);
                printf("%.1f\n", temp);
            }
        }
    } 
    else {
        printf("Unable to open data.csv\n");
        return 1;
    }

    fclose(filePtr);
    return 0;
}
