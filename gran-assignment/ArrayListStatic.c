#include "ArrayListStatic.h"

void initList(List *list){
    list->count = 0;
}

List createList(){
    List list;
    list.count = 0;    
    return list;
}

bool insertFront(List *list, int item){
    if (list->count < MAX) {
        // Shift all elements to the right
        for (int i = list->count; i > 0; i--) {
            list->elems[i] = list->elems[i - 1];
        }
        // Insert the new item at the front
        list->elems[0] = item;
        list->count++;
        return true;
    }
    return false;
}

bool insertRear(List *list, int item){
    if (list->count < MAX) {
        // Insert the item at the end
        list->elems[list->count] = item;
        list->count++;
        return true;
    }
    return false;
}

bool insertAt(List *list, int item, int index){
    if (index >= 0 && index <= list->count && list->count < MAX) {
        // Shift elements to the right to make space
        for (int i = list->count; i > index; i--) {
            list->elems[i] = list->elems[i - 1];
        }
        // Insert the new item
        list->elems[index] = item;
        list->count++;
        return true;
    }
    return false;
}

bool deleteFront(List *list){
    if (list->count > 0) {
        // Shift all elements to the left
        for (int i = 0; i < list->count - 1; i++) {
            list->elems[i] = list->elems[i + 1];
        }
        list->count--;
        return true;
    }
    return false;
}

bool deleteRear(List *list){
    if (list->count > 0) {
        list->count--;
        return true;
    }
    return false;
}

bool deleteAt(List *list, int index){
    if (index >= 0 && index < list->count) {
        // Shift elements to the left to fill the gap
        for (int i = index; i < list->count - 1; i++) {
            list->elems[i] = list->elems[i + 1];
        }
        list->count--;
        return true;
    }
    return false;
}

void display(List list){
    printf("List{");
    for (int i = 0; i < list.count; i++) {
        printf("%d", list.elems[i]);
        if (i < list.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
