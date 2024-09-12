#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ArrayListStatic.h"
#include "ArrayListStatic.c" // Changed this to include the header file

int main() {
    List list;
    int item;

    initList(&list);
    display(list);

    // Example of inserting an item at the front
    item = 5; // You can change this to any number
    if (insertFront(&list, item)) {
        printf("Inserted %d at the front of the list.\n", item);
    } else {
        printf("Failed to insert %d at the front of the list.\n", item);
    }

    display(list);
    
    return 0;
}
