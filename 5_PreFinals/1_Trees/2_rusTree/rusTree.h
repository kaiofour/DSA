#ifndef RUS_TREE_H
#define RUS_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;


void initTree(NodePtr *tree);
NodePtr newBranch(int data);
bool insertTrav(NodePtr *tree, int data);
bool insertRecur(NodePtr *tree, int data);
bool deleteTNode(NodePtr *tree, int data);


#endif