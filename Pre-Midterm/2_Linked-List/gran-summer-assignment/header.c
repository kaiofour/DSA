#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"


void initpersonList(PersonList *myList){
    myList->count = 5;
    
    strcpy(myList->persons[0].name, "Patrick");
    strcpy(myList->persons[1].name, "Gran");
    strcpy(myList->persons[2].name, "Godwin");
    strcpy(myList->persons[3].name, "Cobar");
    strcpy(myList->persons[4].name, "Karen");
    
    myList->persons[0].age = 27;
    myList->persons[1].age = 25;
    myList->persons[2].age = 30;
    myList->persons[3].age = 22;
    myList->persons[4].age = 30;
    
    myList->persons[0].sex = 'M';
    myList->persons[1].sex = 'M';
    myList->persons[2].sex = 'M';
    myList->persons[3].sex = 'M';
    myList->persons[4].sex = 'F';
}

Person createPerson(String name, int age, char sex){
    Person p;

    strcpy(p.name, name);
    p.age = age;
    p.sex = sex;

    return p;
}


bool addPersonFront(PersonList *myList, Person p){
    myList->count++;
    for(int i=myList->count;i>=0;i--){
        myList->persons[i + 1] = myList->persons[i];
    }
    myList->persons[0] = p;
}

PersonList removePersonFront(PersonList *myList){
    for(int i=0;i<myList->count;i++){
        myList->persons[i] = myList->persons[i+1];
    }
    myList->count--;
}


void displayPerson(PersonList myList){
    printf("%-5s | %-20s | %-5s | %-s\n", "ID", "NAME", "AGE", "SEX");
   for(int i=0;i<myList.count;i++){
        printf("%5d | %20s | %5d | %c\n", i+1, myList.persons[i].name, myList.persons[i].age, myList.persons[i].sex);
   }
}