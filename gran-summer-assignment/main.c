#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.c" //changed this to header.c sir kay vscode ako text editor gigamit



int main() {
    
    PersonList myList;
    Person p;

    initpersonList(&myList);
    displayPerson(myList);  

    addPersonFront(&myList, createPerson("Maria", 1, 'M'));
    displayPerson(myList);    

    removePersonFront(&myList);
    displayPerson(myList);
    
    
    
    return 0;
}
