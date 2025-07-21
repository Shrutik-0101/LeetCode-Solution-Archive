/*
Goal: Generate all possible subsets (also called the power set) of the input array nums.

Total subsets for n elements = 2^n
where n is the size of nums.
The number of subsets is 2^n, where n is the length of nums.
So we will loop from 0 to 2^n - 1 to generate all subsets

Trick:
Use bitmasking to represent the inclusion/exclusion of each element.
Each number from 0 to (1 << n) - 1 represents a unique combination of n bits.
If the i-th bit in num is set (1) → include nums[i] in the subset.

Key Insight:
Bit 1 → element is included
Bit 0 → element is excluded
So:
For n = 3, we have 2^3 = 8 subsets:
num = 0b000 (for n = 3) → empty subset
num = 0b101 (for n = 3) → include elements at indices 0 and 2
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int num = 0; num < (1 << n); num++) {
            vector<int> sub;
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    sub.push_back(nums[i]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};