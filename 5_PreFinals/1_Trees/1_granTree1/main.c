#include "bintree.h"

int main(){
    
    NodePtr bin;
    initBin(&bin);
    
    printf("~~Iterative~~\n\n");
    
    verify(insertIter(&bin, 222));
    verify(insertIter(&bin, 111));
    verify(insertIter(&bin, 333));
    verify(insertIter(&bin, 100));
    verify(insertIter(&bin, 1000));
    verify(insertIter(&bin, 250));
    verify(insertIter(&bin, 500));
    
    printf("\nRoot = %d\n", bin->data);
    printf("Left = %d\n", bin->left->data);
    printf("Right = %d\n", bin->right->data);
    printf("Left, Left = %d\n", bin->left->left->data);
    printf("Right, Right = %d\n", bin->right->right->data);
    printf("Right, Left = %d\n", bin->right->left->data);
    printf("Right, Right, Left = %d\n", bin->right->right->left->data);
    
    printf("\n\n~~Recursive~~\n\n");
    
    NodePtr bin2;
    initBin(&bin2);
    verify(insertRecur(&bin2, 222));
    verify(insertRecur(&bin2, 111));
    verify(insertRecur(&bin2, 333));
    verify(insertRecur(&bin2, 100));
    verify(insertRecur(&bin2, 1000));
    verify(insertRecur(&bin2, 250));
    verify(insertRecur(&bin2, 500));
    
    
    printf("\nRoot = %d\n", bin2->data);
    printf("Left = %d\n", bin2->left->data);
    printf("Right = %d\n", bin2->right->data);
    printf("Left, Left = %d\n", bin2->left->left->data);
    printf("Right, Right = %d\n", bin2->right->right->data);
    printf("Right, Left = %d\n", bin2->right->left->data);
    printf("Right, Right, Left = %d\n", bin2->right->right->left->data);
    
    return 0;
}