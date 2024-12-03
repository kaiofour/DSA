#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define QUEUE_MAX 6
#define MAXPATH 15

typedef struct {
    char vertex;
    int weight
} Edge;

typedef struct {
    Edge conn[QUEUE_MAX];
    int front
    int rear;
} Queue;

typdef struct {
    Edge data;
    struct node *link;
} *Connection;

typedef struct {
    Connection arr[MAX_CONNECTION];
    int count;
} Graph;

typedef struct {
    Edge arr[MAX_CONNECTION][MAX_CONNECTION];
    int count;
} MatrixGraph;
