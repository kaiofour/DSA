#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "MyStack.h"
#include "MyStack.c"

#include "Student.h"
#include "Student.c"

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