#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 23

typedef int LIST[MAX];
typedef enum {TRUE, FALSE} Boolean;

Boolean BinarySearchTechnique(LIST L, int x)
{
    int LB, UB, mid;

    LB = 0;
    UB = MAX - 1;

    while (LB <= UB)
    {
        mid = (LB + UB) / 2; //index tracking of mid variable

        if (L[mid] == x)
        {
            return TRUE;
        }
        else if (L[mid] < x)
        {
            LB = mid + 1; //index changes based of the comparison between mid and x
        }
        else
        {
            UB = mid - 1; //index changes based of the comparison between mid and x
        }
    }

    return FALSE;
}

int main()
{

    LIST L = {1, 2, 3 , 4, 5, 6, 7 , 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

    int x = 10;

    if (BinarySearchTechnique(L, x) == TRUE)
        printf("Element %d found in the list.\n", x);
    else
        printf("Element %d not found in the list.\n", x);

    return 0;
}
