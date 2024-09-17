#include <stdio.h>
#include <stdlib.h>

/**
 * @data structure
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node, *NodePtr;

/**
 * @functions
 */
void createList(NodePtr *l, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*l == NULL) {
        *l = newNode; // Use *l to access the original list
    } else {
        NodePtr current = *l;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node *l) {
    for(; l != NULL; l = l->next){
        printf("%d ", l->data);
    }
}


void append(NodePtr *l, int data){
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    NodePtr current = *l;
    while(current->next){
        current = current->next;
    }

    current->next = newNode;
}

// void append2(NodePtr *l, int data){
//     NodePtr newNode = malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     NodePtr current;
//     for(current = *l; &(*l)->next; l = &(*l)->next) {}

//     current->next = newNode;
// }

void append2(NodePtr *l, int data) {
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*l == NULL) {
        *l = newNode;
    } else {
        NodePtr *current = l;
        while ((*current)->next) {
            current = &((*current)->next);
        }
        (*current)->next = newNode;
    }
}

void append3(NodePtr *l, int data) {
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*l == NULL) {
        *l = newNode;
    } else {
        NodePtr current = *l;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * @main function
 */
int main() {
    NodePtr l = NULL;
    createList(&l, 1);
    append(&l, 2);
    append2(&l, 3);
    displayList(l);
    return 0;
}