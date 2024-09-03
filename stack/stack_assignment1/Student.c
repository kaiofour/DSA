#include <stdio.h>
#include <string.h>
#include "Student.h"


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