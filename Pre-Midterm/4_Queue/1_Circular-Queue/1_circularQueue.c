#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[20];

typedef struct {
    String fname;
    String lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    bool sex; //1 is Male //2 is Female
    String program;
    int year;
} Student;

typedef struct {
    Student *studList;
    int max;
    int rear;
    int front;
} QueueADT;

void initQueue(QueueADT *q, int max);
QueueADT createQueue(int max);
bool isEmpty(QueueADT q);
bool isFull(QueueADT q);
bool makeEmpty(QueueADT *q);
bool enqueue(QueueADT *q, Student s);
bool dequeue(QueueADT *q);
Student front(QueueADT q);
void visualize(QueueADT q); // Allows traversal and visualization as a clock
void display(QueueADT q); // No traversal allowed
Name createName(String fname, String lname);
Student createStudent(int studID, Name studName, bool sex, String program, int year);

int main () {
    QueueADT q = createQueue(5);
    // Add your test cases here

    return 0;
}

void initQueue(QueueADT *q, int max) {
    q->max = max;
    q->studList = malloc(sizeof(Student) * max);
    q->front = 0;
    q->rear = -1;
}

QueueADT createQueue(int max) {
    QueueADT q;
    initQueue(&q, max);
    return q;
}

bool isEmpty(QueueADT q) {
    return q.rear == -1;
}

bool isFull(QueueADT q) {
    return (q.rear + 1) % q.max == q.front;
}

bool makeEmpty(QueueADT *q) {
    if (q->studList) {
        free(q->studList);
        q->studList = NULL;
        q->front = 0;
        q->rear = -1;
        return true;
    }
    return false;
}

bool enqueue(QueueADT *q, Student s) {
    if (isFull(*q)) {
        return false; // Queue is full
    }
    q->rear = (q->rear + 1) % q->max;
    q->studList[q->rear] = s;

    // If this is the first element being inserted, adjust front
    if (q->front == -1) {
        q->front = q->rear;
    }

    return true;
}

bool dequeue(QueueADT *q) {
    if (isEmpty(*q)) {
        return false; // Queue is empty
    }

    // Move front one step ahead circularly
    if (q->front == q->rear) { 
        // Queue is now empty after this dequeue
        q->front = 0;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->max;
    }

    return true;
}

Student front(QueueADT q) {
    if (!isEmpty(q)) {
        return q.studList[q.front];
    }
    // Return a default student if the queue is empty
    Student emptyStudent = {0, {"", ""}, 0, "", 0};
    return emptyStudent;
}

void visualize(QueueADT q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q.front;
    do {
        printf("[%d] Student ID: %d, Name: %s %s, Program: %s, Year: %d\n",
               i, q.studList[i].studID, q.studList[i].studName.fname,
               q.studList[i].studName.lname, q.studList[i].program,
               q.studList[i].year);
        i = (i + 1) % q.max;
    } while (i != (q.rear + 1) % q.max);
}

void display(QueueADT q) {
    if (!isEmpty(q)) {
        Student s = front(q);
        printf("Front Student ID: %d, Name: %s %s, Program: %s, Year: %d\n",
               s.studID, s.studName.fname, s.studName.lname, s.program, s.year);
    } else {
        printf("Queue is empty.\n");
    }
}

Name createName(String fname, String lname) {
    Name personName;
    strcpy(personName.fname, fname);
    strcpy(personName.lname, lname);
    return personName;
}

Student createStudent(int studID, Name studName, bool sex, String program, int year) {
    Student stud;
    stud.studID = studID;
    stud.studName = studName;
    stud.sex = sex;
    strcpy(stud.program, program);
    stud.year = year;

    return stud;
}
