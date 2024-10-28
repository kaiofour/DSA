#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;



void initBin (NodePtr *bin);
NodePtr newBranch (int data);
void verify(bool truth);
bool insertIter(NodePtr *bin, int data);
bool insertRecur(NodePtr *bin, int data);

#endif