/*
Purpose:
Find a peak element in the array — an element strictly greater than its neighbors.

Key Concepts Used:
Binary Search (O(log n) time)

A peak satisfies: arr[i] > arr[i-1] && arr[i] > arr[i+1]

Algorithm Breakdown:
Edge Cases:
If array has only one element → return index 0.
If the first element is greater than the second → return 0.
If the last element is greater than the second last → return n - 1.

Binary Search between index 1 and n-2:
Check mid-point:
If arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] → return mid (peak found).
If increasing slope → search right (low = mid + 1)
Else → search left (high = mid - 1)

Why It Works:
A peak is guaranteed to exist in any array. Binary search narrows down the search efficiently.
*/

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1]){
                return mid;
            }
            else if(arr[mid] > arr[mid - 1]) low = mid + 1;
            else high = mid -1;
        }
        return -1;
    }
};