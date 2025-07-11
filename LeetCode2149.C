/*
Goal: Rearrange array so positive and negative numbers alternate: [+, -, +, -, ...]

Approach:
Create a new array using malloc to store the result.

Use two pointers:
posIndex = 0 for positive numbers (even indices)
negIndex = 1 for negative numbers (odd indices)

Loop through original array:
If number is positive → place at posIndex, increment by 2
If number is negative → place at negIndex, increment by 2
*/

#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* vrr = (int*)malloc(numsSize * sizeof(int));
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            vrr[negIndex] = nums[i];
            negIndex += 2;
        }
        else {
            vrr[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    *returnSize = numsSize;
    return vrr;
}