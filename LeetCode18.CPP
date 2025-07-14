/*
Idea:
Fix two numbers, find the other two using two pointers.
Use sorting + nested loops + two pointers.

Steps:
Sort the array.
Loop i from 0 to n-4
Skip duplicates.
Loop j from i+1 to n-3
Skip duplicates.
Set left = j+1, right = n-1

While left < right:
Calculate sum = nums[i] + nums[j] + nums[left] + nums[right]
If sum == target → save quadruplet, skip duplicates, move both
If sum < target → 
move left++
If sum > target →
move right--

Tricks:
Sort array first.
Use long long for sum to avoid integer overflow.
Always skip duplicates for i, j, left, and right.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left; --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};