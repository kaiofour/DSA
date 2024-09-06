#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "MyData.h"
#include "queue.c"


int main() {

    Queue q = createQueue();

    enqueue(&q, createStudent(12345678, createName("Trent", "Guevara"), 'M', "BSIT"));
    enqueue(&q, createStudent(23101122, createName("Russel", "Cantagas"), 'M', "BSIT"));
    enqueue(&q, createStudent(23456789, createName("Walter", "Caballero"), 'M', "BSIT"));
    
    printf("Queue - FIFO: First in First Out Principle\n");
    // printf("ID: %-20d | NAME: %-10s, %-15s | SEX: %-5c | PROGRAM: %-8s\n", q.head->elem.studID, //id
    //                                                                     q.head->elem.studName.lname, //lastname
    //                                                                     q.head->elem.studName.fname, //fname
    //                                                                     q.head->elem.sex, //sex
    //                                                                     q.head->elem.program); //program


    display(q);

    //calling function for queue front implmentation 
    printf("\n\nData in front of the Queue -- ID: %-20d\n", front(q));
    printf("\n\nData in front of the Queue -- ID: %-20s\n", front(q));
    return 0;
}

//create queue (implementation, done)
//enqueue (implementation, done)
//front
//dequeue
//isEmpty
//enqueue
//insertSorted
//insertSorted
//insertSorted
//getStudent
//makeNull
//free memory for queue
