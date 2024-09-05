#ifndef MYDATA_H
#define MYDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct { 
    char fname[20];
    char lname[20];
} Name;

typedef struct {
    int studID;
    Name studName;
    char sex;
    char program[10];
} Student, Data;

// typedef struct node {
//     Data elem;
//     struct node *link;
// } NodeType, *NodePtr;

// typedef struct {
//     NodePtr head;
//     NodePtr tail;
// } Queue;

#endif
