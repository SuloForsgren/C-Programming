#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the max room name length, max and min temperatures and csv file line length
#define MAX_ROOM_LENGTH 40
#define MAX_TEMP 30
#define MIN_TEMP 0
#define BUFFER_SIZE 256

//printBar function prints the dashes
void printBar(float temperature) {
    int num_dashes = (int)(temperature * 2); //make a variable for holding the number of dashes and convert the floating number to integer
    if (temperature < MIN_TEMP || temperature > MAX_TEMP) { //Check if temperature is below 0 or above 30
        printf("X\n");
    } else {
        for (int i = 0; i < num_dashes; i++) { //For loop prints the dashes
            printf("-");
        }
        printf("\n"); //Newline after every row
    }
}

//Function for checking if valid room name is found from the user input and if found successfully then print dashes. If not then print room not found and exit program
void printRoomTemperature(FILE *file, const char *room) {
    int room_found = 0;
    char buffer[BUFFER_SIZE];
    
    //Read lines from the csv file and "tokenize" them
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *token = strtok(buffer, ","); //Get the lefthand side of the string (temperature)
        
        if (token != NULL) {
            float temperature = atof(token); //String to float
            token = strtok(NULL, ","); //Get the righthand side of the string (room name)

            if (token != NULL) {
                token[strcspn(token, "\n")] = '\0'; // Remove newline
                
                //Compare room names and print the room name once. Also print dashes(bar) from the temperature data
                if (strcmp(token, room) == 0) {
                    if (room_found == 0) {
                        printf("%s\n", room);
                    }
                    room_found = 1;
                    printf("%.1f ", temperature);
                    printBar(temperature);
                }
            }
        }
    }
    //If there weren't any matches for the room name then throw an error message.
    if (!room_found) {
        printf("%s is not a room!\n", room);
    }
}

//Main function handling opening of the csv file and user input.
int main() {
    FILE *file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char room[MAX_ROOM_LENGTH];
    printf("Enter the room name: ");
    fgets(room, MAX_ROOM_LENGTH, stdin);
    room[strcspn(room, "\n")] = '\0';
    printRoomTemperature(file, room);

    //Close file and end the program
    fclose(file);
    return 0;
}