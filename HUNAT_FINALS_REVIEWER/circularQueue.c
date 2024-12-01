#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 8

/**
 * Queue ADT Definition
 * - a list or collection with the restriction that insertion
 * can be performed at one end (rear) and deletion can be 
 * performed at the other end (front).
 */



typedef struct {
    char elems[MAX];
    int front;
    int rear;
} Queue;
typedef enum {TRUE, FALSE} Boolean;

//Queue Operations
//init() [DONE]
//enqueue()
//dequeue()
//front()
//isEmpty() [DONE]
//isFull()
Queue initQueue();
Boolean isEmpty(Queue Q);
Boolean isFull(Queue Q);

char front(Queue Q);
void enqueue(Queue *Q, char x);
void dequeue(Queue *Q);

void displayQueue(Queue Q);
void displayQueueV2(Queue Q);
/**
 * MAIN_FUNCTION
 */
int main()
{
    Queue Q = initQueue();

    printf("%d", isEmpty(Q)); //just the same with 0:1
}



//START OF FUNCTION DEFINITIONS
Queue initQueue()
{
    Queue temp;
    temp.front = 0;
    temp.rear = MAX-1;

    return temp;
}

//queue is empty if the difference between the front and rear is one cell
Boolean isEmpty(Queue Q)
{
    return ((Q.rear + 1) % MAX == Q.front) ? TRUE : FALSE; //TRUE, FALSE
}

//queue is full if the difference between the front and rear is two cells
Boolean isFull(Queue Q)
{
    return ((Q.rear + 2) % MAX == Q.front) ? 0 : 1;
}

char front(Queue Q)
{
    //just using a longer expression of !isEmpty
    return ( (Q.rear+1)%MAX != Q.front) ? Q.elems[Q.front] : '#';
    // return (!isEmpty(Q)) ? Q.elems[Q.front] : '#';
}

void enqueue(Queue *Q, char x)
{
    if(!isEmpty(*Q))
    {
        Q->rear = (Q->rear+1) % MAX;
        Q->elems[Q->rear] = x;
    }
}

void displayQueue(Queue Q)
{
    if (!isEmpty(Q)) // Check if the queue is not empty
    {
        int temp = Q.front; // Store the original front position
        while (Q.front != (Q.rear + 1) % MAX) // Loop until reaching the rear
        {
            printf("%c ", Q.elems[Q.front]); // Print the element at the front
            Q.front = (Q.front + 1) % MAX; // Move front to the next position
        }
        Q.front = temp; // Restore the original front position
        printf("\n");
    }
    else
    {
        printf("Empty Queue!\n"); // Output if the queue is empty
    }
}

void displayQueueV2(Queue Q)
{
    while(!isEmpty(Q))
    {
        printf("%d ", front(Q));
        dequeue(&Q);
    }
}

void dequeue(Queue *Q)
{
    if(!isEmpty(*Q))
    {
        Q->front = (Q->front+1) % MAX;
    }
}
