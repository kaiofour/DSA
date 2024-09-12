#ifndef HEADER_H
#define HEADER_H
#define MAX 10
#include <stdbool.h>


typedef char String[20];

typedef struct{
    String name;
    int age;
    char sex;
} Person;

typedef struct{
    Person persons[MAX];
    int count;
} PersonList;

Person createPerson(String name, int age, char sex);

void initpersonList(PersonList *myList);
void displayPerson(PersonList myList);
bool addPersonFront(PersonList *mylist, Person p);
PersonList removePersonFront(PersonList *mylist);



#endif