/*
Every element in the sorted array appears exactly twice except for the single element
We know that if we take any element at an even index (0-indexed)
The next element should be the same.
Similarly, if we take any element at an odd index, the previous element should be the same.
Therefore, we can use binary search to compare the middle element with its adjacent elements to determine which side of the array the single element is on.

If the middle element is at an even index, then the single element must be on the right side of the array,
Since all the elements on the left side should come in pairs.
Similarly, if the middle element is at an odd index, then the single element must be on the left side of the array.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[left];
    }
};