# Process
# Sort the positions.
# Use binary search to maximize the minimum distance between the balls.
# Define a helper function to check if it is possible to place the balls with at least d distance apart.
# Adjust the search range based on the helper function's result.

# Solution
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        n=len(position)
        low=1
        high=position[-1]-position[0]
        while low<=high:
            mid=(low+high)//2
            balls_placed=1
            prev_position=position[0]
            for i in range(1,n):
                if position[i]-prev_position>=mid:
                    balls_placed+=1
                    prev_position=position[i]
            if balls_placed>=m:
                low=mid+1
                highest_force=mid
            else:
                high=mid-1
        return highest_force                    