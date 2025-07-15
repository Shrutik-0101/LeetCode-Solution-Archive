/*
This code implements a binary search to find the position to insert a target value.

If the target is found, it returns the index.

If not, it returns the index where target should be inserted to maintain the sorted order.

Time complexity: O(log n) due to binary search.

Key idea: use left and right pointers to narrow the search space.

If not found, left will point to the correct insertion position.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;        
    }
};