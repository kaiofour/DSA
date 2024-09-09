#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalit Input. Please input a positive number\n");
        return 1;
    }
    arr = (int*) malloc(num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    i = 0;
    int end = num - 1;
    for(int i=0; i<(num/2); i++) {
        int temp = arr[i];
        arr[i] = arr[end - i];
        arr[end - i] = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}