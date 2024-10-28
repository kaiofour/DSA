#include "bintree.h"

void verify(bool truth){
    printf("%s\n", truth == true ? "Succeeded." : "Failed.");
}

void initBin (NodePtr *bin){
    (*bin) = NULL;
}

NodePtr newBranch (int data){
    NodePtr new = malloc(sizeof(NodeType));
    new->left = new->right = NULL;
    new->data = data;
    
    return new;
}

bool insertIter(NodePtr *bin, int data){
    bool truth = false;
        
    NodePtr *trav = bin;
        
    while(*trav != NULL){
            
        ((*trav)->data > data) ? (trav = &(*trav)->left) : (trav = &(*trav)->right);
            
    }
        
    *trav = newBranch(data);
    truth = true;
    
    return truth;
}

bool insertRecur(NodePtr *bin, int data){
    bool truth = false;
    
    if((*bin) == NULL){
        (*bin) = newBranch(data);
        truth = true;
    } else {
        NodePtr *trav = bin;
        
        ((*trav)->data > data) ? (trav = &(*trav)->left) : (trav = &(*trav)->right);
        
        return insertRecur(trav, data);
    }
    
    return truth;
}