#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *elems; //present = 1, = absent = 0
    int count;
    int max;
} Set;

/**@new activity
 * typedef char Set;
 * 
 */

Set createSet(int max); //done
void initSet(Set *s, int max); //done

bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);
bool isElement(Set s, int item);
bool isSubset(Set a, Set b);


Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b);

/**
 * main function
 */
int main () { 
    Set s = createSet(5);
    printf("%d ", addElement(&s, 1));
    printf("%d ", addElement(&s, 2));
    printf("%d ", addElement(&s, 3));
    printf("%d ", addElement(&s, 4));
    printf("%d ", addElement(&s, 5));
    //printf("%d ", addElement(&s, 6));
    
    displaySet(s);

    return 0;
}

void initSet(Set *s, int max) {
    s->elems = calloc(sizeof(int), max);
}
Set createSet(int max) {
    Set s;
    initSet(&s, max);
    s.count = 0;
    s.max = max;
    return s;
}
bool addElement(Set *s, int item) {
    if(item <= s->max) {
        //printf("Set is not full.");
        s->elems[item] = item;
        s->count++;
        return 1;
    } else return 0;
}
bool removeElement(Set *s, int item) {
    for(int i=0; i<s->max; i++) {
        if(s->elems[i] == item) {
            s->elems[i] = 0;
            return 0;
        } else return 1;
    }
}
void displaySet(Set s) {
    printf("\n");
    printf("{");
    for(int i=0; i<s.count; i++) {
        if(addElement(&s, i)==1) {
            printf("%d ", s.elems[i]);
        }
    
    }    
    printf("\n");
}