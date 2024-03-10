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
    
    //While loop comparing every file row's room name to user input and then proceeds to print dashes if true. 
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char temp_str[20], room_name[MAX_ROOM_LENGTH];
        float temperature;
        sscanf(buffer, "%[^,],%s", temp_str, room_name); //%[^,] --> keep reading characters from buffer until encountering comma and then split result's lefthand side to 'temp_str' and righthand side to 'room_name'
        temperature = atof(temp_str); //str to float conversion

        if (strcmp(room_name, room) == 0) {
            room_found = 1;
            printf("%.1f ", temperature);
            printBar(temperature); //print the dashes using function printBar
        }
    }

    if (!room_found) {
        printf("Room not found.\n");
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
    scanf("%s", room);

    printRoomTemperature(file, room);

    fclose(file);
    return 0;
}