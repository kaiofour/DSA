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


void display(Queue q) {
    // while () {
        
    // }
}
bool enqueue(Queue *q, Data d);

bool dequeue(Queue *q) {
    if (!isEmpty(*q)) {

        
    }
}
Data front(Queue q);
void makeNull(Queue *q); //challenge: don't use dequeue
Name *getStudent(Queue q, String program, char sex);

bool insertSorted(Queue *q, Data d);
