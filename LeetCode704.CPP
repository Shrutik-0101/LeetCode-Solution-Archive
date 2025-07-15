/*
Process: 
We have to find the middle index that divides the search space into two halves.
We need to compare the value at the middle index nums[mid] with target,
The purpose of this step is to cut one half that is guaranteed not to contain target.

If nums[mid] = target, it means we find target, and the job is done! We can break the loop by returning mid.
If nums[mid] < target, combined with the array is sorted, we know that all values in the left half are smaller than target,
So we can safely cut this half by letting left = mid + 1.
If nums[mid] > target, it means all values in the right half are larger than target and can be cut safely!
So we use right = mid - 1 to cut the right half.
This process continues until we either find target or exhaust the search space.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = int(nums.size()) - 1;
        
        // Under this condition
        while (left <= right) {
            // Get the middle index and the middle value.
            int mid = left + (right - left) / 2;
            
            // Case 1, return the middle index.
            if (nums[mid] == target) {
                return mid;
            } 
            // Case 2, discard the smaller half.
            else if (nums[mid] < target) {
                left = mid + 1;   
            } 
            // Case 3, discard the larger half.
            else {
                right = mid - 1;
            }
        }
        
        // If we finish the search without finding target, return -1.
        return -1;
    }
};