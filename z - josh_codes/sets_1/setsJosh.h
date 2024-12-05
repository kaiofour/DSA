#ifndef SETSJOSH_H
#define SETSJOSH_H

#define MAX 10
typedef struct{
    int items[MAX];
    int count;
} List;

void insertFront(List* list, int val);
void insertRear(List* list, int val);
void insertInto(List* list, int val, int index);
void deleteFront(List* list);
void deleteRear(List* list);
void deleteItem(List* list, int item);
void display(List list);
void deleteAllOccurence(List *list, int item);
#endif 