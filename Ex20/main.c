#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main() {
    srand(time(NULL));

    int debug_level;
    printf("Enter debug level (0 - 4): ");
    scanf("%d", &debug_level);

    set_debug_level(debug_level);

    for (int i = 1; i <= 5; i++) {
        int random_debug_level = rand() % 5;
        dprintf(random_debug_level, "This is message %d\n", i);
    }

    return 0;
}