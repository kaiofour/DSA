/**
 * @file insertCC2.c
 * @author Raffi
 * @date 2019-03-11
 * @brief This program implements a min heap and inserts elements into it, maintaining the heap property.
 * @details The heap property states that the parent node is always smaller than or equal to its children.
 */

/**
 * @struct arrHeap
 * @brief A min heap, implemented as an array.
 * @var arrHeap::arr
 *   An array of integers, representing the elements in the heap.
 * @var arrHeap::count
 *   The number of elements currently in the heap.
 */

/**
 * @fn void InsertHeap(arrHeap *H, int val);
 * @brief Inserts a value into the heap, maintaining the heap property.
 * @param H the heap to insert the value into
 * @param val the value to insert
 * @details This function will insert the value into the heap, and then call Heapify() to restore the heap property.
 *   If the heap is full, it will print an error message and return.
 */

/**
 * @fn void Heapify(arrHeap H[], int pos);
 * @brief Restores the heap property for the heap. It starts at the given position
 *   and moves up the tree, swapping elements until the heap property is restored.
 * @param H the heap to restore the property for
 * @param pos the position to start at
 * @details This function will iterate up the tree, swapping the current element with its parent if it is smaller than the parent.
 *   It will continue to do this until the heap property is restored, or it reaches the root of the tree.
 */

/**
 * @fn void HeapDisplay(arrHeap H);
 * @brief Prints out the elements of the heap.
 * @param H the heap to print the elements of
 * @details This function will print out the elements of the heap, one by one, to the console.
 */

/**
 * @fn void InitHeap(arrHeap *H);
 * @brief Initializes the heap, setting the count to 0.
 * @param H the heap to initialize
 * @details This function will set the count of the heap to 0, effectively "erasing" the heap.
 */

/**
 * @fn int ParentPos(int pos);
 * @brief Calculates the position of the parent node, given the position of the current node.
 * @param pos the position of the current node
 * @return the position of the parent node
 * @details This function will calculate the position of the parent node, by subtracting 1 from the current position and then dividing by 2.
 */

/**
 * @fn int LeftChild(int pos);
 * @brief Calculates the position of the left child node, given the position of the current node.
 * @param pos the position of the current node
 * @return the position of the left child node
 * @details This function will calculate the position of the left child node, by multiplying the current position by 2 and then adding 1.
 */

/**
 * @fn int RightChild(int pos);
 * @brief Calculates the position of the right child node, given the position of the current node.
 * @param pos the position of the current node
 * @return the position of the right child node
 * @details This function will calculate the position of the right child node, by multiplying the current position by 2 and then adding 2.
 */

/**
 * @fn void Swap(int *x, int *y);
 * @brief Swaps the values of two integers.
 * @param x the first integer to swap
 * @param y the second integer to swap
 * @details This function will swap the values of the two integers, by using a temporary variable to store one of the values.
 */



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
void Heapify(arrHeap H[], int pos);
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
 * FUNCTION_DEFINITIONS
 */

/**
 * FUNCTION InsertHeap
 * Inserts a value into the heap, maintaining the heap property.
 * If the heap is full, it will print an error message and return.
 * @param H the heap to insert the value into
 * @param val the value to insert
 */
void InsertHeap(arrHeap H[], int val)
{
    if (H->count == MAX)
    {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    H->arr[H->count] = val;
    H->count++;
    
    Heapify(H, H->count-1);
}

/**
 * FUNCTION Heapify
 * Restores the heap property for the heap. It starts at the given position
 * and moves up the tree, swapping elements until the heap property is restored.
 * @param H the heap to restore the property for
 * @param pos the position to start at
 */
void Heapify(arrHeap H[], int pos)
{
    int cur_pos = pos; 
    while(cur_pos > 0 && H->arr[cur_pos] < H->arr[ParentPos(cur_pos)] )
    {
        Swap(&H->arr[ParentPos(cur_pos)], &H->arr[cur_pos]);
        cur_pos = ParentPos(cur_pos);
    }
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

void InitHeap(arrHeap *H)
{
    H->count = 0;
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

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


