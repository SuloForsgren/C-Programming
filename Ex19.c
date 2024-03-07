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


int compare_by_name(const void *a, const void *b) {
    const menu_item *menu_a = (const menu_item *)a;
    const menu_item *menu_b = (const menu_item *)b;
    return strcmp(menu_a->name, menu_b->name);
}

int compare_by_price(const void *a, const void *b) {
    const menu_item *menu_a = (const menu_item *)a;
    const menu_item *menu_b = (const menu_item *)b;
    return (menu_a->price > menu_b->price) - (menu_a->price < menu_b->price);
}


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


    while (1) {
        int choice;
        printf("Choose sorting order:\n1. Sort by name\n2. Sort by price \n");
        scanf("%d", &choice);
    
        if (choice == 1) {
            qsort(menu, count, sizeof(menu_item), compare_by_name);
            break;
        }
        else if (choice == 2) {
            qsort(menu, count, sizeof(menu_item), compare_by_price);
            break;
        }
    }
    
    printf("Sorted Menu:\n");
    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}