#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "MyData.h"

    /**
 * LINKED LIST IMPLEMENTATION FUNCTION DEFINITIONS
 */

//set 
Name createName(String fname, String lname) {
    Name temp;
    strcpy(temp.fname, fname);
    strcpy(temp.lname, lname);
    return temp;
}

Student createStudent(int studID, Name studName, char sex, String program) {
    Student temp;
    temp.studID = studID;
    temp.studName = studName;
    temp.sex = sex;
    strcpy(temp.program, program);

    return temp;
}

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


void display(Queue q) { //visualize
    NodePtr curr = q.head;
    while (curr != NULL) {
        printf("Program: %s, Sex: %c, Name: %s %s\n", curr->elem.program, curr->elem.sex, curr->elem.studName.fname, curr->elem.studName.lname);
        curr = curr->link;
    }
}


bool enqueue(Queue *q, Data d){
    NodePtr demo = malloc(sizeof(NodeType));
    if (demo == NULL) {  // checks if memory allocation was successfull or not
        printf("Malloc not allocated\n");
        return false;
    }
    demo->elem = d;     // insert data
    demo->link = NULL;  // sets demo's(node) next to NULL
    
    if (isEmpty(*q)) {
        q->head = demo;
        q->tail = demo;
    } else {
        q->tail->link = demo;
        q->tail = demo; // sets tail also in case of another case
    }
    return true;
}

bool dequeue(Queue *q) { // delete front?
    if (!isEmpty(*q)) {
        NodePtr temp = q->head;
        q->head = q->head->link; //store the 2nd node(q->head->link) inside the queue in the node-pointer(q->head)
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp); //deletes temp(original first node of the queue)
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
    while(!isEmpty(*q)) { //basically like dequeue but do it all over again until queue is empty
        temp = q->head;
        q->head = q->head->link;
        free(temp);
    }
    q->tail = NULL;
}

// Name *getStudent(Queue q, String program, char sex) {
//     NodePtr curr = q.head;
//     while (curr != NULL) {
//         if (strcmp(curr->elem.program, program) == 0 && curr->elem.sex == sex) {
//             return &curr->elem; // return the matching student's data
//         }
//         curr = curr->link;
//     }
//     return NULL; // not found
// }

// Inserts a new element d into the queue in a sorted manner
bool insertSorted(Queue *q, Data d) {
    NodePtr newNode = malloc(sizeof(NodeType)); //create node(nodeptr)
    if (newNode == NULL) { //checking if node is allocated or not
        printf("Malloc not allocated\n");
        return false;
    }
    newNode->elem = d; //sets data and its link to null
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

// trent's insertSorted 
// void insertSorted(Queue *q, Data d){

//     Queue tempQ = createQueue();

//     while(d.studID > q->head->elem.studID){
//         enqueue(&tempQ, front(q));
//         dequeue(q);
//     }

//     enqueue(&tempQ, d);

//     while(q->head){
//         enqueue(&tempQ, front(q));
//         dequeue(q);
//     }

//     while(!isEmpty(tempQ)){
//         enqueue(q, front(&tempQ));
//         dequeue(&tempQ);
//     }
// }