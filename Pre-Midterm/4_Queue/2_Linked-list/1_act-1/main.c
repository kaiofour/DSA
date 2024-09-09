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

//init queue & create queue  (implementation, done)
//enqueue (implementation, done) 
//front (implementation, done)
//dequeue
//isEmpty (check)
//enqueue
//insertSorted
//insertSorted
//insertSorted
//getStudent
//makeNull (more or less understood)
//free memory for queue
