#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
/**
 * @data_structure
 */
typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct {
    Name elems[MAX];
    int front;
    int rear;
} NQueue;


/**
 * @queue_operations/functions
 */
void initNQueue(NQueue *nq) {
  nq->front = NULL;
  nq->rear = NULL;
}
bool isEmpty(NQueue nq) {
  return (nq.front == NULL) ? true : false;   
}
bool isFull(NQueue nq) {
  return (nq.elems == MAX) ? true : false; //not sure if this'll work
}

void visualizeQueue(NQueue nq) {
  for(nq = t)
}

void displayQueue(NQueue nq) {
  if(isEmpty(nq)) {
    printf("Queue is empty\n");
  }
  for(int i=0; i < nq.)
}

bool enqueue(NQueue *nq, Name n) {

}

  
bool dequeue(NQueue *nq);
Name front(NQueue nq);

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString);
Name* filterNames(NQueue *nq, char *filterString){
// printf("Wonderhoy!");
Name* fn = malloc(sizeof(Name) * MAX);
Name temp;
int j = 0;
int i = nq->front; // 0
int rear = nq->rear;
// printf("\nFront: %d", nq->front);
// printf("\nRear: %d", nq->rear);
while(i != rear){
if(strcmp(nq->elems[i].lname, filterString) == 0){
fn[j] = nq->elems[i];
dequeue(nq);
// printf("Name: %s", fn[j].lname);
j++;
} else {
temp = nq->elems[i];
dequeue(nq);
enqueue(nq, temp);
}
i = (i + 1) % MAX;
}

// printf("Wonderhoy!");
fn[j] = createName("", "");
// printf("Name: %s", fn[j].lname);
return fn;
}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(Queue *q, Data d){ // insert data in correct position
NodePtr curr = q->head;
Data temp;
if(curr == NULL){
enqueue(q, d);
return true;
}
while(d.studID > curr->elem.studID && !isEmpty(*q)){
temp = curr->elem;
dequeue(q);
if(isEmpty(*q)){

}
enqueue(q, temp);
greet();
}
enqueue(q, d);
return true;
}


/**
 * @main_function
 */
int main() {
    printf("Hello World");

    

    return 0;
}