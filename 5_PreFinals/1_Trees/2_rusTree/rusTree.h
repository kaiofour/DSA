#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef RUS_TREE_H
#define RUS_TREE_H

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;


void initTree(NodePtr *tNode);
NodePtr newBranch(int data);
void verify(bool truth);
bool insertTrav(NodePtr *tNode, int data);
bool insertRecur(NodePtr *tNode, int data);
bool deleteTNode(NodePtr *tNode, int data);


#endif