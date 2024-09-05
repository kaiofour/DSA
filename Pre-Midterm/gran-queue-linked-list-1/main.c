#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "MyData.h"
#include "queue.c"


int main() {

    Queue q = createQueue();
    
    enqueue(&q, createStudent(23101122, createName("Russel", "Edullantes"), 'M', "BSIT"));
    

    printf("ID: %-20d | NAME: %-10s %-15s | SEX: %-5c | PROGRAM: %-8s\n", q.head->elem.studID, //id
                                                                        q.head->elem.studName.lname, //lastname
                                                                        q.head->elem.studName.fname, //fname
                                                                        q.head->elem.sex, //sex
                                                                        q.head->elem.program); //program
    return 0;
}

