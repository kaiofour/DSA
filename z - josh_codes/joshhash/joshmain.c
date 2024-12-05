#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashjosh.h"



int getHash(Student s);
void initDictionary(Dictionary *d);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary d);

void main(){
    Dictionary studList;
    initDictionary(&studList);
    Student josh = {23102689,"Josh",true,"BSIT",2};
    Student jansen = {23102442,"Jansen",true,"BSIT",2};
    Student jio = {21102442,"Jio",true,"BSIT",2};
    Student jio2 = {21102443,"Jio2",true,"BSIT",2};
    Student jio3 = {21102444,"Jio3",true,"BSIT",2};
    
    addStudent(&studList,josh);
    addStudent(&studList,jansen);
    addStudent(&studList,jio);
    addStudent(&studList,jio2);
    addStudent(&studList,jio3);
    
    Student test = getStudent(studList,josh);
    // visualize(studList);
    
    removeStudent(&studList, jio2);
    visualize(studList);
}

void initDictionary(Dictionary *d){
    for (int i = 0; i < MAX; ++i){
        d->elems[i] = NULL;
    }
    d->count = 0;
}

int getHash(Student s){
    int hash = 0;

    for (int i = 0; i < 31; ++i){
        hash += (s.studID >> i) & 1;
    }
    for (int i = 0; i < 3; ++i){
        hash += s.studName[i];
    }
    for (int i = 0; s.program[i] != '\0'; ++i){
        hash += s.program[i];
    }
    return hash % MAX;
}

bool addStudent(Dictionary *d, Student s){
    int hash = getHash(s);
    NodePtr *trav;
    NodePtr temp = malloc(sizeof(struct node));
    temp->stud = s;
    int found = 0;
    if (temp != NULL){
        for (trav = &(d->elems[hash]); *trav != NULL && (*trav)->stud.studID <= s.studID; trav = &(*trav)->link){
            if ((*trav)->stud.studID == s.studID){
                found = 1;
            }
        }
        if (found == 0){
            temp->link = *trav;
            *trav = temp;
        }
        return true;
    }
    return false;
}

Student getStudent(Dictionary d, Student s){
    int hash = getHash(s);
    NodePtr trav;
    for (trav = (d.elems[hash]) ; trav != NULL; trav = trav->link){
        if (trav->stud.studID == s.studID){
            return trav->stud;
        }
    }
}

bool removeStudent(Dictionary *d, Student s){
    int hash = getHash(s);
    NodePtr* trav;
    NodePtr temp;
    for (trav = &(d->elems[hash]); *trav != NULL; trav = &(*trav)->link){
        if ((*trav)->stud.studID == s.studID){
            temp = *trav;
            *trav = temp->link;
            free(temp);
            break;
        }
    }
}

void visualize(Dictionary d){
    NodePtr trav;
    for (int i = 0; i < MAX; ++i){
        printf("Index [%d] - ",i);
        if (d.elems[i] != NULL){
            for (trav = d.elems[i]; trav != NULL; trav = trav->link){
                printf("ID: %d Name: %s Course: %s",trav->stud.studID, trav->stud.studName, trav->stud.program);
                if (trav->link != NULL){
                    printf(" -> ");
                }
            }
        } else{
            printf("List is empty");
        }
        printf("\n");
    }
}
//first three letters of the name, number of 1s in student id, entire thing in program % MAX; 