#ifndef ARRAY_LIST_DYNAMIC_H
#define ARRAY_LIST_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elems; // Pointer to the dynamic array
    int count;  // Number of elements currently in the array
    int capacity; // Capacity of the array
} DynamicArray;

void initArray(DynamicArray *array, int initialCapacity);
void freeArray(DynamicArray *array);
bool insertFront(DynamicArray *array, int item);
bool insertRear(DynamicArray *array, int item);
bool insertAt(DynamicArray *array, int item, int index);
bool deleteFront(DynamicArray *array);
bool deleteRear(DynamicArray *array);
bool deleteAt(DynamicArray *array, int index);
void display(DynamicArray array);

#endif
