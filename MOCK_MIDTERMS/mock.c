#ifndef MOCK_c
#define MOCK_c
#define MAX 10
#define SIZE 5
/**
 * @data_structure
 */
typedef char String[20];

typedef struct {
    String city;
    int zip;
} Address;

typedef struct {
    int id;
    String name;
    Address add;
} Person;

typedef struct {
    Person *list; //a dynamic array
    int count; //will be top for the stack
} PersonList, StackLAist, PersonCloseDict;

typedef struct {
    Person list[MAX];
    int front;
    int rear;
} QueueAList;

typedef struct Node {
    Person p;
    struct node *link;
} NodeType, *NodePtr, *StackLList;

typedef struct {
    NodePtr *list[SIZE];
    int count;
} PersonOpenDict;

typedef struct {
    NodePtr head;
    NodePtr tail;
} QueuePersonList;
#endif