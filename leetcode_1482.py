# Process
# Use binary search on the number of days.
# Define a helper function to check if it is possible to make m bouquets in d days by counting consecutive available flowers.
# Adjust the search range based on the helper function's result to find the minimum possible days.

# Solution
from typing import List

class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1
        
        def canMakeBouquets(days: int) -> bool:
            bouquets = 0
            flowers = 0
            for bloom in bloomDay:
                if bloom <= days:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                        if bouquets >= m:
                            return True
                else:
                    flowers = 0
            return bouquets >= m
        
        left, right = min(bloomDay), max(bloomDay)
        while left < right:
            mid = (left + right) // 2
            if canMakeBouquets(mid):
                right = mid
            else:
                left = mid + 1
        
        return left