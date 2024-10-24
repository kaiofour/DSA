#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rusTree.c"

// typedef struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// } NodeType, *NodePtr;

int main()
{
    NodePtr rusTree;
    initTree(&rusTree);

    insertTrav(&rusTree, 8);
    insertTrav(&rusTree, 9);
    insertTrav(&rusTree, 10);



    return 0;
}
