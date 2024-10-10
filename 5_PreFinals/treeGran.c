#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;

void initBin(NodePtr *tNode);
NodePtr newBranch(int data);
void verify(bool truth);
bool insertTrav(NodePtr *tNode, int data);
bool insertRecur(NodePtr *tNode, int data);
bool deleteTNode(NodePtr *tNode, int data);

int main() {
    NodePtr tree;
    initBin(&tree);
    printf("~~Iterative~~\n\n");
    
    
    verify(insertTrav(&tree, 222));
    verify(insertTrav(&tree, 111));
    printf("\nRoot = %d\n", tree->data);
    printf("Left = %d\n", tree->left->data);
   
    /**
     * yepyep
     */
    
    NodePtr tree2;
    initBin(&tree2);
    printf("\n\n~~Recursive~~\n\n");

    verify(insertRecur(&tree2, 222));
    verify(insertRecur(&tree2, 111));
    printf("\nRoot = %d\n", tree2->data);
    printf("Left = %d\n", tree2->left->data);


    return 0;
}

void initBin(NodePtr *tNode) {
   *tNode = NULL;
}

NodePtr newBranch(int data) {
    NodePtr tNode = malloc(sizeof(NodeType));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return tNode;
}

void verify(bool truth) {
    printf("%s", truth == true ? "Succeeded\n" : "Fail\n");
}

bool insertTrav(NodePtr *tNode, int data) {
    bool truth;
    NodePtr *trav = tNode;
    while(*trav != NULL) {
        ((*trav)->data > data ? (trav = &(*trav)->left) : (trav = &(*trav)->right));
    }

    *trav = newBranch(data);
    truth = true;

    return truth;
}

bool insertRecur(NodePtr *tNode, int data) {
    bool truth = false;
    NodePtr *trav = tNode;
    if(*trav == NULL) {
        *trav = newBranch(data);
    } else {
        ((data < (*trav)->data) ? (trav = &(*trav)->left) : (trav = &(*trav)->right));
         //it works, then call the function again to loop
         return insertRecur(trav, data);
    }

    return true;
}

bool deleteTNode(NodePtr *tNode, int data) {

}
