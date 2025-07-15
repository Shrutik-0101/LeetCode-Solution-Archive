/*
Process:
This code finds the starting and ending positions of a given target in a sorted vector nums using binary search.
It handles duplicates and returns [-1, -1] if the target is not present.

The main function searchRange() calls a helper function findBound() twice:
First with isFirst = true to find the leftmost (first) occurrence of the target.
Second with isFirst = false to find the rightmost (last) occurrence.

findBound() performs binary search and:
Stores the index in res when nums[mid] == target.
If searching for the first occurrence, it continues searching the left half.
If searching for the last occurrence, it continues searching the right half.
Final result is returned as a vector {left, right}.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        int right = findBound(nums, target, false);
        return {left, right};
    }
    int findBound(vector<int>& nums, int target, bool isFirst){
        int l = 0, r = nums.size() - 1, res = -1;
        while(l <= r){
            int mid = l + ( r - l )/ 2;
            if(nums[mid] == target){
                res = mid;
                if(isFirst) r = mid - 1;
                else l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid  + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};