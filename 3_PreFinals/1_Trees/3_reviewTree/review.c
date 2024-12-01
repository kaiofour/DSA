#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *RusTreeNode;


void initTree(NodePtr *rusTNode);
NodePtr createNode(int data);
void insert2Tree(NodePtr *rusTNode, int data);


void inOrder(NodePtr rusTNode);
void preOrder(NodePtr rusTNode);
void postOrder(NodePtr rusTNode);
/**
 * @main_function
 */
int main()
{
    RusTreeNode rusTree;

    initTree(&rusTree);
    
    insert2Tree(&rusTree, 4);
    insert2Tree(&rusTree, 5);
    insert2Tree(&rusTree, 10);
    insert2Tree(&rusTree, 7);
    insert2Tree(&rusTree, 8);
    insert2Tree(&rusTree, 1);

    preOrder(rusTree);
    return 0;
}

void initTree(NodePtr *rusTNode)
{
    (*rusTNode) = NULL;
}

NodePtr createNode(int data)
{
    NodePtr newNode = malloc(sizeof(NodeType));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert2Tree(NodePtr *rusTNode, int data) //BST insert
{
    if (*rusTNode == NULL) {
        *rusTNode = createNode(data);
    } else if (data < (*rusTNode)->data) {
        insert2Tree(&(*rusTNode)->left, data);
    } else {
        insert2Tree(&(*rusTNode)->right, data);
    }
}

void inOrder(NodePtr rusTNode)
{
    if(rusTNode == NULL) {
        return;
    }

    inOrder(rusTNode->left);
    printf("%d ", rusTNode->data);
    inOrder(rusTNode->right);
}

void preOrder(NodePtr rusTNode) //need terminating statement
{
    if(rusTNode == NULL) {
        return;
    }

    printf("%d ", rusTNode->data);
    preOrder(rusTNode->left);
    preOrder(rusTNode->right);
}

void postOrder(NodePtr rusTNode)
{
    if(rusTNode == NULL) {
        return;
    }

    postOrder(rusTNode->left);
    postOrder(rusTNode->right);
    printf("%d ", rusTNode->data);
}