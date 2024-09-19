#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    NodePtr elems[20];
    int count
} HashTable;


/**
 * @function_prototypes
 */
int getHash(Student s);
/**
 * Get the Hast based on the summation of the first 3 letters of the name plus the letters in the program and must be able to return a value from 0-19.
 */

void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
bool delete(HashTable *ht, Student s);

void visualizeTable(HashTable ht);


/**
 * @main_function
 */
int main() {
    

    return 0;
}


/**
 * @function_definitions
 */
int getHash(Student s);
/**
 * Get the Hast based on the summation of the first 3 letters of the name plus the letters in the program and must be able to return a value from 0-19.
 */

void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
bool delete(HashTable *ht, Student s);

void visualizeTable(HashTable ht);