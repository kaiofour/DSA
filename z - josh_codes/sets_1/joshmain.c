#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int elems[MAX];
    int count;
} Set;

Set createSet();
bool addElement(Set* s, int item);
bool removeElement(Set* s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b);
int cardinality(Set s);
bool isElement(Set s, int item);

int main(){
    Set mySet = createSet();
    Set mySet2 = createSet();
    addElement(&mySet, 3);
    addElement(&mySet, 1);
    addElement(&mySet, 4);
    addElement(&mySet, 6);
    addElement(&mySet, 7);
    addElement(&mySet, 8);
    
    addElement(&mySet2, 2);
    addElement(&mySet2, 1);
    addElement(&mySet2, 4);
    addElement(&mySet2, 11);
    addElement(&mySet2, 7);
    addElement(&mySet2, 9);
    
    displaySet(mySet);
    displaySet(mySet2);
}

Set createSet(){
    Set x;
    x.count = 0;
    for (int i = 0; i < MAX; ++i){
        x.elems[i] = 0;
    }
    return x;
}

bool addElement(Set* s, int item){
    if (s->elems[item] >= 1){
        return false;
    }
    s->elems[item] = 1;
    s->count++;
    return true;
}

bool removeElement(Set *s, int item){
    if (s->elems[item] == 0){
        return false;
    }
    s->elems[item] = 0;
    s->count++;
    return true;
}

void displaySet(Set s){
    printf("{");
    int x = 0;
    for (int i = 0; i < MAX; ++i){
        if (s.elems[i]==1){
            printf("%d",i);
            x++;
            if (s.count > x){
                printf(", ");
            }
        }
    }
    printf("}\n");
}

Set unionSet(Set a, Set b){
    Set c = createSet();
    for (int i = 0; i < MAX; ++i){
        if (a.elems[i] == 1 || b.elems[i] == 1){
            c.elems[i] = 1;
            c.count++;
        }
    }
    return c;
}

Set intersectionSet(Set a, Set b){
    Set c = createSet();
    for (int i = 0; i < MAX; ++i){
        if (a.elems[i] == 1 && b.elems[i] == 1){
            c.elems[i] = 1;
            c.count++;
        }
    }
    return c;
}

Set differenceSet(Set a, Set b){
    Set c = createSet();
    for (int i = 0; i < MAX; ++i){
        if (a.elems[i] == 1 && b.elems[i] == 0){
            c.elems[i] = 1;
            c.count++;
        }
    }
    return c;
}

Set symmetricDifferenceSet(Set a, Set b){
    Set c = createSet();
    for (int i = 0; i < MAX; ++i){
        if (a.elems[i] !=  b.elems[i]){
            c.elems[i] = 1;
            c.count++;
        }
    }
    return c;
}

int cardinality(Set s){
    return s.count;
}
bool isElement(Set s, int item){
    if (s.elems[item]==1){
        return true;
    } else{
        return false;
    }
}