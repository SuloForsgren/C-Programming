#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_LENGTH 20
#define MAX_TEMP 30
#define MIN_TEMP 0
#define BUFFER_SIZE 256

void printBar(float temperature) {
    int num_dashes = (int)(temperature * 2);
    if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
        printf("X\n");
    } else {
        for (int i = 0; i < num_dashes; i++) {
            printf("-");
        }
        printf("\n");
    }
}

int validateRoomName(const char *room) {
    if (strlen(room) > MAX_ROOM_LENGTH) {
        printf("Error: Room name exceeds maximum length.\n");
        return 0;
    }
    return 1;
}

void printRoomTemperature(FILE *file, const char *room) {
    int room_found = 0;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char temp_str[20], room_name[MAX_ROOM_LENGTH];
        float temperature;
        sscanf(buffer, "%[^,],%s", temp_str, room_name);
        temperature = atof(temp_str);
        if (strcmp(room_name, room) == 0) {
            room_found = 1;
            printf("%.1f ", temperature);
            printBar(temperature);
        }
    }

    if (!room_found) {
        printf("Room not found.\n");
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char room[MAX_ROOM_LENGTH];
    printf("Enter the room name: ");
    scanf("%s", room);

    if (!validateRoomName(room)) {
        fclose(file);
        return 1;
    }

    printRoomTemperature(file, room);

    fclose(file);
    return 0;
}