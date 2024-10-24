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
    bool isEmpty;
} Student;

typedef struct {
    Student elems[20];
    int count;
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

    Student s1 = {1, "John Doe", "Computer Science", 2020, false};
    Student s2 = {2, "Jane Doe", "Engineering", 2020, false};

    insert(&ht, s1);
    insert(&ht, s2);

    visualizeTable(ht);

    return 0;
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
 * 5 letters of the name plus the letters in the
 * program and must be able to return a value from
 * 0-19.
 */

void initDictionary(HashTable *ht) {
    for (int i = 0; i < 20; i++) {
        ht->elems[i].isEmpty = true;
    }
    ht->count = 0;
}
bool insert(HashTable *ht, Student s) {
    int hash = getHash(s);
    int originalHash = hash;
    while (!ht->elems[hash].isEmpty) {
        hash = (hash + 1) % 20;
        if (hash == originalHash) {
            return false; // Table is full
        }
    }
    ht->elems[hash] = s;
    ht->elems[hash].isEmpty = false;
    ht->count++;
    return true;
}
bool delete(HashTable *ht, Student s) {
    int hash = getHash(s);
    int originalHash = hash;
    while (!ht->elems[hash].isEmpty && strcmp(ht->elems[hash].studName, s.studName) != 0) {
        hash = (hash + 1) % 20;
        if (hash == originalHash) {
            return false; // Student not found
        }
    }
    if (ht->elems[hash].isEmpty) {
        return false; // Student not found
    }
    ht->elems[hash].isEmpty = true;
    ht->count--;
    return true;
}

void visualizeTable(HashTable ht) {
    for (int i = 0; i < 20; i++) {
        if (!ht.elems[i].isEmpty) {
            printf("Bucket %d:\n", i);
            printf("  %s (%d) - %s\n", ht.elems[i].studName, ht.elems[i].studID, ht.elems[i].program);
        }
    }
}