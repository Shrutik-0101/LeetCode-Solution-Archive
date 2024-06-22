# Process
# Use a sliding window with two deques to maintain the maximum and minimum values in the current window.
# Expand the window by adding elements and adjust the window size by removing elements from the left to maintain the absolute difference within the limit.
# Keep track of the maximum window size seen during the process.

# Solution
from collections import deque
class Solution:
    
    def longestSubarray(self, nums, limit):
        minDeque = deque()
        maxDeque = deque()
        left = 0
        max_len = 0
        
        for right in range(len(nums)):
            while minDeque and nums[minDeque[-1]] >= nums[right]:
                minDeque.pop()
            while maxDeque and nums[maxDeque[-1]] <= nums[right]:
                maxDeque.pop()
            
            minDeque.append(right)
            maxDeque.append(right)
            
            while nums[maxDeque[0]] - nums[minDeque[0]] > limit:
                left += 1
                if minDeque[0] < left:
                    minDeque.popleft()
                if maxDeque[0] < left:
                    maxDeque.popleft()
            
            max_len = max(max_len, right - left + 1)
        
        return max_len