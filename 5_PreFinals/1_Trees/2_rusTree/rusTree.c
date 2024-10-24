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
        if((*trav) == NULL)
        {
            return false;
        }

        ((*trav)->data > data ? (trav = &(*trav)->left) : (trav = &(*trav)->right));                
    }

    (*trav) = newBranch(data);

    return true;
}

bool insertRecur(NodePtr *tree, int data)
{
    
}

// bool deleteTNode(NodePtr *tree, int data)
// {

// }