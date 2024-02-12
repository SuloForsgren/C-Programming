#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define read_length 15

typedef struct node {
 int number;
 struct node *next;
} nnode;

int main(void) {

    char input[read_length];
    int value = 0, count = 0;
    struct node *head;

    while(1) {
        printf("Enter a number or 'end': ");
        fgets(input, read_length, stdin);
        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "%d", &value) == 1) {
            nnode *nextLinkedNode = (nnode *)malloc(sizeof(nnode));
            if (nextLinkedNode == NULL) {
                printf("Memory allocation error!");
            }
            else if (count == 0) {
                nextLinkedNode->number = value;
                nextLinkedNode->next = NULL;
                head = nextLinkedNode;
                count++;
            }
            else if (count > 0) {
                nextLinkedNode->number = value;
                nextLinkedNode->next = head;
                head = nextLinkedNode;
                count++;
            }
        }

        else if (strcmp(input, "end") == 0) {
            nnode* integers = head;
            while (integers != NULL) {
                printf("%d\n", integers->number);
                integers = integers->next;
            }

            integers = head;
            while (integers != NULL) {
                nnode* clean = integers;
                integers = integers->next;
                free(clean);
            }
            break;
        }
        
        else {
            printf("Error\n");
        }
    }

    return 0;
}