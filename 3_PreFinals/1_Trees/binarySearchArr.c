#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {NOT_FOUND, FOUND} truth;


void bin_search(int arr[], int LB, int UB, int x);
bool kaw_binSearch(int arr[], int LB, int UB, int x);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = (sizeof(arr) / sizeof(int)) - 1;

    bin_search(arr, 0, length, 5);
    printf("\n");

    printf("%s", kaw_binSearch(arr, 0, length, 5) ? "FOUND" : "NOT_FOUND");

    return 0;
}


void bin_search(int arr[], int LB, int UB, int x)
{
    int mid;

    while(LB <= UB)
    {
        mid = (LB + UB) / 2;

        if(arr[mid] == x) 
        {
            printf("Found");
            return;
            //return true;
        }
        else if(arr[mid] < x)
        {
            LB = mid + 1;
        }
        else
        {
            UB = mid - 1;
        }
    }

    printf("Not Found");
}


bool kaw_binSearch(int arr[], int LB, int UB, int x)
{
    int mid = (LB + UB)/2;

    for(LB = 0; UB--; LB <= UB && arr[mid] != x)
    {
        ( (arr[mid] > x) ? (UB = mid-1) : (LB = mid+1) );
    }

    return (LB > UB) ? false : true;
}