#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ArrayListDynamic.h"


void initArray(DynamicArray *array, int initialCapacity) {
    array->elems = (int *)malloc(initialCapacity * sizeof(int));
    array->count = 0;
    array->capacity = initialCapacity;
}

void freeArray(DynamicArray *array) {
    free(array->elems);
    array->elems = NULL;
    array->count = 0;
    array->capacity = 0;
}

bool resizeArray(DynamicArray *array, int newCapacity) {
    int *newElems = (int *)realloc(array->elems, newCapacity * sizeof(int));
    if (newElems) {
        array->elems = newElems;
        array->capacity = newCapacity;
        return true;
    }
    return false;
}

bool insertFront(DynamicArray *array, int item) {
    if (array->count == array->capacity) {
        if (!resizeArray(array, array->capacity * 2)) {
            return false;
        }
    }
    for (int i = array->count; i > 0; i--) {
        array->elems[i] = array->elems[i - 1];
    }
    array->elems[0] = item;
    array->count++;
    return true;
}

bool insertRear(DynamicArray *array, int item) {
    if (array->count == array->capacity) {
        if (!resizeArray(array, array->capacity * 2)) {
            return false;
        }
    }
    array->elems[array->count] = item;
    array->count++;
    return true;
}

bool insertAt(DynamicArray *array, int item, int index) {
    if (index < 0 || index > array->count) {
        return false;
    }
    if (array->count == array->capacity) {
        if (!resizeArray(array, array->capacity * 2)) {
            return false;
        }
    }
    for (int i = array->count; i > index; i--) {
        array->elems[i] = array->elems[i - 1];
    }
    array->elems[index] = item;
    array->count++;
    return true;
}

bool deleteFront(DynamicArray *array) {
    if (array->count == 0) {
        return false;
    }
    for (int i = 0; i < array->count - 1; i++) {
        array->elems[i] = array->elems[i + 1];
    }
    array->count--;
    return true;
}

bool deleteRear(DynamicArray *array) {
    if (array->count == 0) {
        return false;
    }
    array->count--;
    return true;
}

bool deleteAt(DynamicArray *array, int index) {
    if (index < 0 || index >= array->count) {
        return false;
    }
    for (int i = index; i < array->count - 1; i++) {
        array->elems[i] = array->elems[i + 1];
    }
    array->count--;
    return true;
}

void display(DynamicArray array) {
    printf("DynamicArray{");
    for (int i = 0; i < array.count; i++) {
        printf("%d", array.elems[i]);
        if (i < array.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
