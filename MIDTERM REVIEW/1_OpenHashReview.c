#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {found = }
#define MAX 20
//use 65% as the packing density

/**
 * @data_structure
 */

typedef char String[20];

typedef struct{
    int studID;
    String studName;
    String program;
    int year;
} Student;

typedef struct node{
    Student stud;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count;
} HashTable, Dictionary;


/**
 * @function_prototypes
 */
/**
 * Get the Hash based on the summation of the first 
 * 3 letters of the name plus the letters in the 
 * program and must be able to return a value from
 * 0-19.
 */
int getHash(Student s);
void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
bool remove(HashTable *ht, Student s);
Student createStudent(int studID, String studName, String program, int year);
void visualizeTable(HashTable ht);
/**
 * need to implement search and sorting as well
 * also double hashing, quadratic hashing, &
 * rehashing
 */

/**
 * @main_function
 */
int main() {
    HashTable ht;
    initDictionary(&ht);
    
    
    
    return 0;
}


/**
 * @function_definitions
 */

/**
 * Get the Hash based on the summation of the first
 * 3 letters of the name plus the letters in the
 * program and must be able to return a value from
 * 0-19.
 */

void initDictionary(HashTable *ht) {
  ht->count = 0;
  for(int i=0; i <= MAX; i++) {
    ht->elems[i] = NULL;
  }
  ht->count = 0;
}

int getHash(Student s) {
    int count;

   for(int i=0; i<3; i++) count += (int)s.studName[i];
   
   return count % MAX;
}

bool insert(HashTable *ht, Student s) { //insert student into index
    int index = getHash(s); //hash index

    NodePtr newNode = malloc(sizeof(NodeType));
    NodePtr trav; //can use NodePtr, just preference

    newNode->stud = s;

    for(trav = &(ht->elems[index]); *trav != NULL && (*trav)->stud.studID <= s.studID; trav = &(*trav)->link) {

    }
    
    
   
    return true;
}

bool addStudent(Dictionary *d, Student s){
    int hash = getHash(s);
    NodePtr *trav;
    NodePtr temp = malloc(sizeof(struct node));
    temp->stud = s;
    int found = 0;
    if (temp != NULL){
        for (trav = &(d->elems[hash]); *trav != NULL && (*trav)->stud.studID <= s.studID; trav = &(*trav)->link){
            if ((*trav)->stud.studID == s.studID){
                found = 1;
            }
        }
        if (found == 0){
            temp->link = *trav;
            *trav = temp;
        }
        return true;
    }
    return false;
}


// bool remove(HashTable *ht, Student s) {
//    // if(s == ht->student)
// }

// void visualizeTable(HashTable ht) { //hash tables aren't usually used for displaying, only for retrieving data(hence, visualize)
    
// }

Student createStudent(int studID, String studName, String program, int year) {
    Student s;
    s.studID = studID;
    strcpy(s.studName, studName);
    strcpy(s.program, program);
    s.year = year;
    return s;
}