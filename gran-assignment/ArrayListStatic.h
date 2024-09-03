#ifndef ARRAY_LIST_STATIC_H
#define ARRAY_LIST_STATIC_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elems[MAX];
    int count;
} List;

void initList(List *list);
List createList(); 
void display(List list);
bool insertFront(List *list, int item);
bool insertRear(List *list, int item);
bool insertAt(List *list, int item, int index);
bool deleteFront(List *list);
bool deleteRear(List *list);
bool deleteAt(List *list, int index);

#endif
