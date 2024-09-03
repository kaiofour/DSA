#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MyData.h"

typedef struct node {
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
} Queue;

typedef char String[20];

void initQueue(Queue *q);
Queue createQueue();

bool isEmpty(Queue q);


void display(Queue q);
bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);
void makeNull(Queue *q);

Name *getStudent(Queue q, String program, char sex);

bool insertSorted(Queue *q, Data d);

#endif
