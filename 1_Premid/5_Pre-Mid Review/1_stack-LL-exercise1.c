#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @data_structure
 */
typedef struct {
    char name[30];
    int age;
    char sex;
} Person;

typedef struct node {
    Person data; //top of the stack if we're looking at the shit idk what im talking about lol
    struct node *link;
} NodeType, *NodePtr, *Stack;

typedef char String[20];

/**
 * @function_protoypes
 */
void initStack(Stack *s);
bool isEmpty(Stack s);
Person createPerson(String name, int age, char sex);
Stack createStack(Stack *s);

void displayStack(Stack s);
bool push(Stack *s, Person p);
bool pop(Stack *s);
Person peek(Stack s);

bool insertSorted1(Stack *s, Person p);
bool insertSorted2(Stack *s, Person p);
void sortStack(Stack *s, bool flag);


/**
 * @main_function
 */
int main(){

  Stack *s;
  createStack(&s);
  printf("%d", isEmpty(s)); //1 empty, 0 not empty;

  return 0;
}

/**
 * @function_definitions
 */
void initStack(Stack *s) {
  *s = NULL;
}
Person createPerson(String name, int age, char sex) {
  Person p;
  strcpy(p.name, name);
  p.age = age;
  p.sex = sex;
  return p;
}

Stack createStack(Stack *s) {
  initStack(&s);
  *s = malloc(sizeof(NodeType));
  return *s;
}

bool isEmpty(Stack s) {
  return s == NULL;
}

void displayStack(Stack s) {
  if(s == NULL) {
    printf("Stack is not allocated / directory is NULL");
    return NULL;
  }

  NodePtr trav = s;
  for(trav = s; trav != NULL; trav = trav->link) {
    printf("%s %d %c\n", trav->data.name, trav->data.age, trav->data.sex);
  }
}

bool push(Stack *s, Person p) {
  NodePtr newNode = malloc(sizeof(NodeType));

  if(isEmpty(&s)) {
    *s = newNode;
    return true;
  } else if (newNode == NULL) {
    return false;
  }
  
  newNode->data = p;
  newNode->link = *s; //set 1st node to be new node

  *s = newNode;
  return true;
}

bool pop(Stack *s) {
  if(*s == NULL) {
    return false;
  }
  Stack temp = *s;
  *s = (*s)->link;
  free(temp);
  return true;
}
Person peek(Stack s) {
  return s->data;
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p);

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p);

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag);