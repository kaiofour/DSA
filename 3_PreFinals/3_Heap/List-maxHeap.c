#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int lastNdx;
} HeapList, *HeapListPtr; // Used either as a Heap or as a List

void initHeapList(HeapListPtr *H);
bool populate(HeapListPtr *H, int data);
void displayList(HeapListPtr H);
void ListToMaxHeap(HeapListPtr *H);

/**
 * @ MAIN_FUNCTION
 */
int main()
{

    HeapListPtr H = NULL; 
    initHeapList(&H);

    printf("%d\n", populate(&H, 1) );
    printf("%d\n", populate(&H, 2) );
    printf("%d\n", populate(&H, 3) );
    printf("%d\n", populate(&H, 4) );
    printf("%d\n", populate(&H, 5) );
    printf("%d\n", populate(&H, 6) );
    printf("%d\n", populate(&H, 7) );
    printf("%d\n", populate(&H, 8) );
    printf("%d\n", populate(&H, 9) );
    printf("%d\n", populate(&H, 10) );
    printf("\n");

    displayList(H);

    return 0;
}

/**
 *  1.) Write the code of the function that will convert the given list into a maxHeap
 */
void ListToMaxHeap(HeapListPtr *H)
{
    
}

void initHeapList(HeapListPtr *H)
{
    (*H) = malloc(sizeof(HeapList));
    (*H)->lastNdx = 0;

    for(int i = 0; i < MAX; i++)
    {
        (*H)->data[i] = -1;
    }
}

bool populate(HeapListPtr *H, int data)
{
    if((*H)->lastNdx < MAX)
    {
        (*H)->data[(*H)->lastNdx] = data;
        (*H)->lastNdx += 1;
        return true;
    }
    
    return false;
}

void displayList(HeapListPtr H)
{
    int i;
    for(i = 0; i < H->lastNdx; i++)
    {
        if(H->data[i] == -1) {
            return;
        } else {
            printf("%d ", H->data[i]);
        }

    }

}

