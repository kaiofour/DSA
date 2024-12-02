#include "rusTree.h"

bool deleteTreeNode(NodePtr *tree, int data) {
    NodePtr *trav = tree;
    NodePtr temp;
    NodePtr *look;

    while (*trav != NULL && (*trav)->data != data) {
        trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
    }

    if (*trav != NULL) {
        temp = *trav;

        if (temp->left != NULL && temp->right != NULL) {
            look = &temp->left;
            while ((*look)->right != NULL) {
                look = &(*look)->right;
            }

            temp->data = (*look)->data;
            temp = *look;
            *look = temp->left;
        } else {
            *trav = (temp->left != NULL) ? temp->left : temp->right;
        }

        free(temp);
        return true;
    }

    return false;
}
