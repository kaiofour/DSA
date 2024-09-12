#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MyData.h"
typedef char String[20];

    //Data Structure
// typedef struct { 
//     char fname[20];
//     char lname[20];
// } Name;

// typedef struct {
//     int studID;
//     Name studName;
//     char sex;
//     char program[10];
// } Student, Data;

typedef struct node {
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
} Queue;


/**
 * LINKED LIST IMPLEMENTATION FUNCTION PROTOTYPES
 */
Name createName(String fname, String lname);
Student createStudent(int studID, Name studName, char sex, String program);
void initQueue(Queue *q);
Queue createQueue(Queue *q);
bool isEmpty(Queue q);
void display(Queue q); 
bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);
void makeNull(Queue *q);
Name *getStudent(Queue q, String program, char sex);
bool insertSorted(Queue *q, Data d);

#endif
