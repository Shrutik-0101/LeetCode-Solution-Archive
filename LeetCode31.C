/*
Key Idea:
We want the next bigger number using the same digits.
So we will be using "Next Lexicographical Permutation" Algorithm.

Steps:
Find the drop point:
Go from right to left.
Find the first digit where nums[i] < nums[i+1].
In 158476531, this is 4 at index 3.
Find the next bigger digit:
From the end, find the smallest number greater than 4.
That’s 5 at index 6.

Swap them:
Swap 4 and 5.

Reverse the tail:
Reverse everything after the original index (i + 1 to end).

This gives the smallest possible number after the swap.
*/

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(int* nums, int start, int numsSize) {
    int i = start, j = numsSize - 1;
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1, numsSize);
}