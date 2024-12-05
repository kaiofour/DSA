#ifndef HASHJOSH_H
#define HASHJOSH_H

#include <stdbool.h>

#define MAX 10

typedef struct{
    int studID;
    char studName[20];
    bool sex;
    char program[8];
    int level;
} Student;

typedef struct node{
    Student stud;
    struct node *link;
} NodeType, *NodePtr;

typedef struct{
    NodePtr elems[MAX];
    int count;
} Dictionary;


#endif 