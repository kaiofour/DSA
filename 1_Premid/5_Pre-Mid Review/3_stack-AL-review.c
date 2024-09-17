#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

/**
 * @data_structure
 */
typedef char String[20];

typedef struct{
    int elems[MAX]; //changed to student elems[MAX];
    int count;
} Stack;

typedef struct {
    int studID;
    String studName;
    String program;
    int year;
} Student;


/**
 * @function_prototypes
 */
Student createStudent(int studID, String studName, String program, int year);
void displayStudent(Student s);
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

/**
 * @main_function
 */
int main(){
    Stack stackA = createStack();

    visualize(stackA);
    push(&stackA, 10);
    push(&stackA, 21);
    push(&stackA, 30);
    push(&stackA, 40);
    push(&stackA, 50);
    push(&stackA, 60);
    visualize(stackA);

    
    for(int i = 0; i < 10; i++) {
        pop(&stackA);
        visualize(stackA);
    }

    Student newStudent = createStudent(23101122, "Russel", "BSIT", 2);
    displayStudent(newStudent);
    return 0;
}


/**
 * @function_definitions
 */
Student createStudent(int studID, String studName, String program, int year) {
    Student newStudent;
    
    newStudent.studID = studID;
    strcpy(newStudent.studName, studName);
    strcpy(newStudent.program, program);
    newStudent.year = year;

    return newStudent;
}


void displayStudent(Student newStudent) {
    printf("%d\n", &newStudent.studID);
    printf("%s\n", newStudent.studName);
    printf("%s\n", newStudent.program);
    printf("%d\n", newStudent.year);
}
Stack createStack(){
    Stack s;

    s.count = 0;

    return s;
}
void initStack(Stack *s){
    s->count = 0;
}

bool isEmpty(Stack s){
    return s.count == 0;
}

bool isFull(Stack s){
    return s.count >= MAX;
}

void visualize(Stack s){
    printf("List: {");
    for(int i=0; i < s.count; ++i){
        printf("%d", s.elems[i]);
        if(i < s.count){
            printf(", ");
        }
    }
    printf("}\n");
}

bool push(Stack *s, int elem){
    if(!isFull(*s)) {
        s->elems[(s->count)++] = elem;
        return true;
    }
    return false;
}

bool pop(Stack *s){
    if(!isEmpty(*s)) {
    (s->count)--;
    return true;
    }

    return false;
}

int peek(Stack s){
    return s.elems[s.count-1];
}

void sortStack(Stack *s, bool flag){
    if(isEmpty(*s)){
        printf("Nothing to sort!\n");
        return;
    }
    Stack temp;
    initStack(&temp);

    while(!isEmpty(*s)){
        Person t = peek(*s);
        pop(s);
        if(isEmpty(temp)){
            push(&temp, t);
            
        } else {
            if(flag){ //ascending
                if(strcmp(t.name, peek(temp).name) > 0){
                push(&temp, t);
                
                } else {
                    while(!isEmpty(temp) && strcmp(t.name, peek(temp).name) < 0){
                        push(s, peek(temp));
                        pop(&temp);
                    }
                push(&temp, t);
                }
            } else { //descending
                if(strcmp(t.name, peek(temp).name) < 0){
                push(&temp, t);
                
                } else {
                    while(!isEmpty(temp) && strcmp(t.name, peek(temp).name) > 0){
                        push(s, peek(temp));
                        pop(&temp);
                    }
                push(&temp, t);
                }
            }
        }
        
    }

    while(!isEmpty(temp)){
        push(s, peek(temp));
        pop(&temp);
    }
    
}
Stack getEven(Stack s){
    Stack evenStack = createStack();
    int item;

    while(!isEmpty(s)) {
        item = peek(s);
        if(item % 2 == 0) {
            push(&evenStack, item);
        }
        pop(&s);
    }

    return evenStack;
}

Stack getStudent(Stack s , String program) {
    
}

void sortStudent(Stack *s) {

}