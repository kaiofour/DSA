#include "rusTree.h"

void initTree(NodePtr *tree)
{
    (*tree) = NULL;
}

NodePtr newBranch(int data)
{
    NodePtr newNode = malloc(sizeof(NodeType));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    return newNode;
}

bool insertTrav(NodePtr *tree, int data)
{
    NodePtr *trav;
    

    for(trav = tree; (*trav) != NULL;)
    {
        ((*trav)->data > data ? (trav = &(*trav)->left) : (trav = &(*trav)->right));                
    }

    (*trav) = newBranch(data);

    return true;
}

bool insertRecur(NodePtr *tree, int data)
{
    NodePtr *trav = tree;

    if(*trav == NULL) //meaning empty
    {
        *trav = newBranch(data);
    }
    else //not empty, keep going to find empty spot
    {
        //go left if less, if not right
        ((data < (*trav)->data) ? (trav = &(*trav)->left) : (trav = &(*trav)->right)); 

        return insertRecur(trav, data);
    }

    return true;
}

void displayTree(NodePtr tree) //pre-order display
{
    if(tree != NULL)
    {
        printf("%d ", tree->data);
        displayTree(tree->left);
        displayTree(tree->right);
    }
}



