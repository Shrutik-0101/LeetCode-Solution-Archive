# ✨✨✨✨✨✨✨✨✨
# Credits: https://leetcode.com/u/SonuDutta/
# ✨✨✨✨✨✨✨✨✨

# Process
# The problem requires minimizing the difference between the largest and smallest values in an array after at most three moves.
# By changing up to three elements to any value, we can effectively remove up to three outliers.
# Thus, the core insight is that we can minimize the range by focusing on changing either the smallest or the largest elements.
# Approach
# Sort the Array:
# Sorting helps us quickly access the smallest and largest elements in a structured manner.
# Consider Edge Case:
# If the array has 4 or fewer elements, we can make all elements the same with three moves, resulting in a difference of 0.
# Analyze Scenarios:
# Post sorting, consider four scenarios:
# Change the three smallest elements to the fourth smallest element.
# Change the two smallest elements and the largest element.
# Change the smallest element and the two largest elements.
# Change the three largest elements to the fourth largest element.
# Compute Differences:
# Calculate the differences for these scenarios.
# Return Minimum Difference:
# The result is the minimum difference computed from the above scenarios.

# Solution
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0
        nums.sort()

        return min(
            nums[-1] - nums[3],
            nums[-2] - nums[2],
            nums[-3] - nums[1],
            nums[-4] - nums[0]
        )
        