/*
Idea:
Fix one number, find two others such that the sum is 0.
Use sorting + two pointers to reduce time complexity.

Steps:
Sort the array.

Loop i from 0 to n-1:

Skip duplicates.

Set left = i+1, right = n-1.

While left < right:
If sum == -nums[i]: save triplet, skip duplicates, move both.
If sum < target: 
move left++
If sum > target:
move right--

Tricks:
Sort first for two-pointer method.
Skip same values to avoid duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> op;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[left] + nums[right];
                if (current_sum == target) {
                    op.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return op;
    }
};