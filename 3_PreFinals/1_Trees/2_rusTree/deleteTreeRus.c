#include "rusTree.h"

bool deleteTreeNode(NodePtr *tree, int data) //delete through traversing
{
    NodePtr *trav; 
    NodePtr temp; //to hold the node to be deleted
    NodePtr *look; //Pointer to find the in-order predecessor


    //traversing to find the node to delete
    while(*trav != NULL && (*trav)->data != data)
    {
        ((trav = data < (*trav)->data) ? (trav = &(*trav)->left) : (trav = &(*trav)->right));    
    }

    //if element is found, proceed to delete it
    if(*trav != NULL)
    {
        temp = *trav;

        //case 1: Node has two children
        if(temp->left != NULL && temp->right != NULL)
        {
            //FIND THE IN-ORDER Predecessor (rightmost node in the left subtree)
            look = &temp->left;
            while ( (*look)->right != NULL)
            {
                look = &(*look)->right;
            }

            //copy the predecessor's data to the current node
            temp->data = (*look)->data;

            //prepare to delete the predecessor
            temp = *look;
            *look = temp->left; //remove the predecessor node
        }
        else
        {
            //case 2: Node has one or no children
            *trav = (temp->left != NULL) ? temp->left : temp->right; //link the child or NULL
        } 

        free(temp);
    }
}