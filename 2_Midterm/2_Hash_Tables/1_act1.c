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
/**
 * Get the Hash based on the summation of the first 
 * 3 letters of the name plus the letters in the 
 * program and must be able to return a value from
 * 0-19.
 */
int getHash(Student s);
void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
bool delete(HashTable *ht, Student s);

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

    Student s1 = {1, "John Doe", "Computer Science", 2020};
    Student s2 = {2, "Jane Doe", "Engineering", 2020};

    insert(&ht, s1);
    insert(&ht, s2);

    visualizeTable(ht);

    return 0;
}


/**
 * @function_definitions
 */
int getHash(Student s) {
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        hash += s.studName[i];
    }
    hash += strlen(s.program);
    return hash % 20;
}
/**
 * Get the Hash based on the summation of the first
 * 3 letters of the name plus the letters in the
 * program and must be able to return a value from
 * 0-19.
 */

void initDictionary(HashTable *ht) {
    for (int i = 0; i < 20; i++) {
        ht->elems[i] = NULL;
    }
    ht->count = 0;
}
bool insert(HashTable *ht, Student s) {
    int hash = getHash(s);
    NodePtr newNode = (NodePtr) malloc(sizeof(NodeType));
    if (!newNode) {
        return false; // Memory allocation failed
    }
    newNode->stud = s;
    newNode->link = ht->elems[hash];
    ht->elems[hash] = newNode;
    ht->count++;
    return true;
}
bool delete(HashTable *ht, Student s) {
     int hash = getHash(s);
    NodePtr current = ht->elems[hash];
    NodePtr previous = NULL;
    while (current && strcmp(current->stud.studName, s.studName) != 0) {
        previous = current;
        current = current->link;
    }
    if (!current) {
        return false; // Student not found
    }
    if (previous) {
        previous->link = current->link;
    } else {
        ht->elems[hash] = current->link;
    }
    free(current);
    ht->count--;
    return true;
}

void visualizeTable(HashTable ht) {
    for (int i = 0; i < 20; i++) {
        NodePtr current = ht.elems[i];
        printf("Bucket %d:\n", i);
        while (current) {
            printf("  %s (%d) - %s\n", current->stud.studName, current->stud.studID, current->stud.program);
            current = current->link;
        }
    }
}