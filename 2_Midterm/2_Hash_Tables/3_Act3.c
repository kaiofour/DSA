#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @data_structure
 */
typedef char String[50];
typedef struct {
    int prodID;
    String prodName;
    int prodQty;
    float prodPrice;
} Product;

typedef struct Node {
    Product prod;
    struct Node *link;
} NodeType, *NodePtr, *Stack;

typedef struct {
    NodePtr *data;
    int count;
    int max;
} ProdDict;
/**
 * function_prototypes
 * 1.) Create a function that converts a product stack into a dictionary. If similar product, exit automatically
 *  adds into the prodQty
 * 2.) Hash function will be based on the ID plus the first 5 characters of the product name
 * 3.) use 70% of the load factor for the dictionary
 * 4.) Open hashing
 * 
/**
/**
 * Stack (push, pop, peek, isEmpty, initStack)
 * Dictionary (insert/add, search/get, delete/remove, display, visualize, initDict)
 */

bool initDict(ProdDict *d);
bool insert(Stack s);
bool search(Stack s);
bool delete(Stack s);
bool visualize()


//stack functions
bool push(Stack *s, Product p);
bool pop(Stack *s, Product *p);
bool peek(Stack s, Product p);
bool isEmpty(Stack s);
bool initStack(Stack *s);

/**
 * @main_function
 */
int main() {
    ProdDict *d = malloc(sizeof(ProdDict));


    return 0;
}

bool initDict(ProdDict *d) {
    d->count = 0;  
    d->max = 10;
    return true;
}

bool push(Stack *s, Product p) {
    
}