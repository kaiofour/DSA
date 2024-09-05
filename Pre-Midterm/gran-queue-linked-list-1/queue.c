#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "MyData.h"



//set 
void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue() {
    Queue q;
    initQueue(&q);
    return q;
}

bool isEmpty(Queue q) {
   return q.head == NULL; //1 is Empty, 0 is NOT Empty
}


// void display(Queue q) {
   
// }


bool enqueue(Queue *q, Data d){
    NodePtr demo = malloc(sizeof(NodeType));
    if (demo == NULL) {
        printf("Malloc not allocated\n");
        return false;
    }
    demo->elem = d;
    demo->link = NULL;
    
    if (isEmpty(*q)) {
        q->head = demo;
        q->tail = demo;
    } else {
        q->tail->link = demo;
        q->tail = demo;
    }
    return true;
}

bool dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        NodePtr temp = q->head;
        q->head = q->head->link;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return true;
    }
    return false;
}

//will return the front/top element of the queue
Data front(Queue q) { 
    if (!isEmpty(q)) {
        return q.head->elem;
    } else {
        printf("Queue is empty\n");
    }
}

 //challenge: don't use dequeue
 // empties the queue without using dequeue
void makeNull(Queue *q) {
    NodePtr temp;
    while(!isEmpty(*q)) {
        temp = q->head;
        q->head = q->head->link;
        free(temp);
    }
    q->tail = NULL
}

// Searches for a student with a specific program and sex in the queue
Name *getStudent(Queue q, String program, char sex) {
    NodePtr curr = q.head;
    while (curr != NULL) {
        if (strcmp(curr->elem.program, program) == 0 && curr->elem.sex == sex) {
            return &curr->elem; // return the matching student's data
        }
        curr = curr->link;
    }
    return NULL; // not found
}

// Inserts a new element d into the queue in a sorted manner
bool insertSorted(Queue *q, Data d) {
    NodePtr newNode = malloc(sizeof(NodeType));
    if (newNode == NULL) {
        printf("Malloc not allocated\n");
        return false;
    }
    newNode->elem = d;
    newNode->link = NULL;

    if (isEmpty(*q) || strcmp(d.program, q->head->elem.program) <= 0) {
        // insert at the beginning of the queue
        newNode->link = q->head;
        q->head = newNode;
        if (q->tail == NULL) {
            q->tail = newNode;
        }
    } else {
        NodePtr curr = q->head;
        while (curr->link != NULL && strcmp(d.program, curr->link->elem.program) > 0) {
            curr = curr->link;
        }
        // insert after the current node
        newNode->link = curr->link;
        curr->link = newNode;
        if (newNode->link == NULL) {
            q->tail = newNode;
        }
    }
    return true;
}