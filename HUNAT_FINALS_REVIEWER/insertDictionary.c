#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 0xD

typedef struct{
    char LN[16], FN[24], MI;
} nametype; 
typedef struct{
    unsigned long IDen;
    nametype name;
    char course[8];
    int year;
} studRec;
typedef struct node{
    studRec stud;
    struct node *next;
} *List;

typedef struct{ 
    List head[SIZE];
    int count;
} Dictionary;

int openHash(unsigned long IDen);

void insertDic(Dictionary *D, studRec S)
{                
    int hash;
    List *ptr, temp;
    hash = openHash(S.IDen);    //determines the hash value
    
    /* Determines the position of the element to be inserted */
    for(ptr = &D->head[hash]; *ptr != NULL && (*ptr)->stud.IDen < S.IDen; ptr = &(*ptr)->next) {}
    
    /* Conditions for a possible insertion */
    if (*ptr == NULL || (*ptr)->stud.IDen != S.IDen) {   //Black_06 and Blank_07 are conditions
        temp = (List) malloc(sizeof(struct node));
        if (temp != NULL) {    
            // Statements to insert the element
        }
    }
}

int main(){
    return 0;
}