# Process
# Greedy approach:
# Use a sliding window to track flips.

# Array to track flips:
# Maintain an array to keep track of whether a flip affects the current position.

# Count flips:
# Flip the bits when necessary to ensure each element becomes 1, and count the number of flips.

# Solution
class Solution(object):
    def minKBitFlips(self, nums, k):
        n = len(nums)
        flipped = 0
        res = 0
        isFlipped = [0] * n
        
        for i in range(n):
            if i >= k:
                flipped ^= isFlipped[i - k]
            if flipped == nums[i]:
                if i + k > n:
                    return -1
                isFlipped[i] = 1
                flipped ^= 1
                res += 1
        
        return res