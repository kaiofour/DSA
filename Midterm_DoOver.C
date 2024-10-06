#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @data_structure
 */
typedef enum {empty = -1, deleted = -2} Flag;
typedef char String[20];

typedef struct {
    int age;
    int studID;
    String name;
} Student;

Student *populate();

/**
 * @main_function
 */
int main() {
    Student *list = populate();
    if (list == NULL) return 0;

    return 0;
}

Student *populate() {
    Student *list = (Student*) malloc(sizeof(Student)*20);
    if(list == NULL) return NULL;

    int i;
    for(i = 0; i < 20; i++) {
        list[i].age = 18 + i;
        list[i].studID = 100 + i;
        sprintf(list[i].name, "Student %d", i+1);
    }

    return list;
}