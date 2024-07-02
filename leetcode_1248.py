# Process
# Use a prefix sum array to count the number of subarrays with exactly k odd numbers.
# Maintain a hash map to track the number of times a specific count of odd numbers has been seen.
# For each element in the array, update the count of odd numbers and use the hash map to determine the number of valid subarrays ending at the current index.

# Solution
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        odd_indices = deque()
        subarrays = 0
        last_popped = -1
        initial_gap = -1

        for i in range(len(nums)):
            # If element is odd, append its index to the deque.
            if nums[i] % 2 == 1:
                odd_indices.append(i)
            # If the number of odd numbers exceeds k, remove the first odd index.
            if len(odd_indices) > k:
                last_popped = odd_indices.popleft()
            # If there are exactly k odd numbers, add the number of even numbers
            # in the beginning of the subarray to the result.
            if len(odd_indices) == k:
                initial_gap = odd_indices[0] - last_popped
                subarrays += initial_gap

        return subarrays