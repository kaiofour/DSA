#include <stdio.h>
#define MAX 100

typedef struct
{
    int arr[MAX];
    int count;
} arrHeap;

void InsertHeap(arrHeap *H, int val);
void InitHeap(arrHeap *H);
void Swap(int *x, int *y);
int ParentPos(int pos);
int LeftChild(int pos);
int RightChild(int pos);
void HeapDisplay(arrHeap H);

/**
 * MAIN FUNCTION
 */
int main()
{
	arrHeap rusHeap;
	InitHeap(&rusHeap);
	
	InsertHeap(&rusHeap, 7);
    InsertHeap(&rusHeap, 2);
    InsertHeap(&rusHeap, 1);
    InsertHeap(&rusHeap, 5);
    InsertHeap(&rusHeap, 3);

    HeapDisplay(rusHeap);
    return 0;
}

/**
 * FUNCTION_DEFINITION
 */

// Function to insert a value into the heap
void InsertHeap(arrHeap *H, int val)
{
    H->arr[H->count] = val;
    H->count++;
    
    Heapify(H, H->count - 1);
}

void Heapify(arrHeap *H, int pos)
{
    int cur_pos = pos; 
    while(cur_pos > 0 && H->arr[cur_pos] > H->arr[ ParentPos(cur_pos) ] )
    {
        Swap(&H->arr[ ParentPos(cur_pos) ], &H->arr[cur_pos]);
        cur_pos = ParentPos(cur_pos);
    }
}

//Function to initialize heap
void InitHeap(arrHeap *H)
{
    H->count = 0;
}

//Function to swap two variables
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int ParentPos(int pos)
{
    return (pos - 1) / 2;
}

int LeftChild(int pos)
{
    return pos * 2 + 1;
}

int RightChild(int pos)
{
    return (pos * 2) + 2;
}

void HeapDisplay(arrHeap H)
{
    int i;
    printf("Heap elements:\n");

    for(i = 0; i < H.count; i++)
    {
        printf("%d ", H.arr[i]);
    }
    printf("\n");
}