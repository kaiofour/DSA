#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 8 //max here refers to edges
#define INFINITY 100 //idk what this is

typedef struct {
    vertex vertexName;
    int weight;
} vertexType; //Similar to NodeType

typedef struct node {
    vertexType vertexInfo;
    struct node* link;
} *vertexPtr;

typedef struct {
    vertexPtr list[MAX_VERTEX];
    int edgeCount;
} weightedGraph;

typedef struct {
    vertex matrix[MAX_VERTEX][MAX_VERTEX];
    int edgeCount;
} matrixGraph;

