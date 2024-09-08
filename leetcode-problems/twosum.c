#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int* arr = (int*) malloc(2 * sizeof(int));
    if (!arr) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }

    free(arr); // No pair found, free the allocated memory
    return arr;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int* sumArray = twoSum(nums, numsSize, target);

    if (sumArray) {
        printf("%d %d\n", nums[sumArray[0]], nums[sumArray[1]]);
        free(sumArray); // Free the allocated memory
    } else {
        printf("No pair found\n");
    }

    return 0;
}