#include <stdio.h>
int arr[100];
int size = 0;

//Function to swap two variables
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to insert a value into the heap
void insert(int val){
    arr[size] = val; // Add the value to the end of the array
    size++; // Increment the size of the heap
    int cur_index = size-1; // Index of the newly inserted element

    // Perform heapify-up operation
    while(cur_index!=0){ // Continue until reaching the root (index 0)
        int parent_index = (cur_index-1)/2; // Calculate the index of the parent node
        if(arr[parent_index] > arr[cur_index]){ // If the parent node is greater than the current node
            swap(&arr[parent_index], &arr[cur_index]); // Swap them
        }
        cur_index = parent_index; // Move up to the parent node
    }
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
	    int value;
	    scanf("%d", &value);
	    insert(value);
	}
	for(int i=0; i<size; i++){
	    printf("%d ", arr[i]);
	}
}

