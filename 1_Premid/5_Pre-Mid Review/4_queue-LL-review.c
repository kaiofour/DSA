#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @data_structure
 */
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

typedef struct node {
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
} Queue;

/**
 * @function_prototypes
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


/**
 * @main_function
 */
int main() {
    Queue q = createQueue(&q);

    enqueue(&q, createStudent(12345678, createName("Trent", "Guevara"), 'M', "BSIT"));
    enqueue(&q, createStudent(23101122, createName("Russel", "Cantagas"), 'M', "BSIT"));
    enqueue(&q, createStudent(23456789, createName("Walter", "Caballero"), 'M', "BSIT"));

    printf("Queue - FIFO: First in First Out Principle\n");
    display(q);

    //calling function for queue front implmentation 
    Data frontNode = front(q);
    printf("\n\nData in front of the Queue || ID: %-10d | NAME: %-10s, %-13s | SEX: %-3C | PROGRAM: %-8s\n", 
                                                                        frontNode.studID, //stud_id
                                                                        frontNode.studName.lname, //lastname
                                                                        frontNode.studName.fname, //fname
                                                                        frontNode.sex, //sex
                                                                        frontNode.program); //program                                                  
    return 0;
}

/**
 * @function_definitions
 */
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

Queue createQueue(Queue *q) {
    Queue *temp = malloc(sizeof(Queue));
    temp = *q;
    initQueue(&temp);
    return temp;
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

void insertSorted2(Queue *q, Data d){

    Data temp;

    while(d.studID > front(*q).studID){
        temp = front(*q);
        dequeue(q);
        enqueue(q, temp);
    }

    enqueue(q, d);

    while(front(*q).studID > d.studID){
        temp = front(*q);
        dequeue(q);
        enqueue(q, temp);
    }
}
