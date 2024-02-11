#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LENGTH 80
#define MENU_LENGTH 40

typedef struct menu_item_ {
 char name[50];
 double price;
} menu_item;

int count = 0;
char line[FILE_LENGTH];

int main(void) {
    FILE *myfile;
    char filename[FILE_LENGTH];
    menu_item menu[MENU_LENGTH];


    printf("Please enter a file name: ");
    scanf("%s", filename);

    strcat(filename, ".txt");
    myfile = fopen(filename, "r");

    if (myfile != NULL) {
        printf("File opened\n");

        while (fgets(line, FILE_LENGTH, myfile) != NULL) {
            char *token = strtok(line, ";");
            strcpy(menu[count].name, token);

            token = strtok(NULL, ";");
            menu[count].price = atof(token);

            count++;

            if (count == MENU_LENGTH) {
                break;
            }
        }

        fclose(myfile);
    }

    else {
        fprintf(stderr, "Couldn't open file.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}