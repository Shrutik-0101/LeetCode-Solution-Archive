/*
Goal:
Count the number of subarrays that sum up to a given value k.

Working Procedure:
Prefix Sum + Hash Map

Use total to store the running sum.

Use a map subNum to store how many times each prefix sum has occurred.

Key logic:
If (total - k) exists in the map, it means there's a subarray ending at current index that sums to k.

Add the frequency of (total - k) to count.

Initialize subNum[0] = 1

Handles case when a subarray starting from index 0 equals k.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};