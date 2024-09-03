#ifndef MY_STACK_H
#define MY_STACK_H
#include <stdbool.h>
#include "Student.h"
#define MAX 5

typedef struct{
    int elems[MAX]; //changed to student elems[MAX];
    int count;
} Stack;

Stack createStack();
void initStack(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, int elem); //int elem changed to Student stud
bool pop(Stack *s);
int peek(Stack s);

//Stack sort(Stack s);

Stack getStudent(Stack s, String program);
Stack getEven(Stack s);
void sortStudent(Stack *s);
#endif

