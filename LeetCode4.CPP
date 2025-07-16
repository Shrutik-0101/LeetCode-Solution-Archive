/*
Purpose:
Find the median of two sorted arrays (can be of different sizes) using a merge-based approach.

Key Concepts:
Simulate the merge process of two sorted arrays (like merge sort).
Track elements at positions mid (and mid-1 if total length is even).
No need to store merged array — just count until median is reached.

Steps:
Compute total size: n1 = a.size() + b.size()
Set index1 = mid - 1, index2 = mid
Merge until cnt == index2, saving values at index1 and index2.
If n1 is odd → return element at index2
If even → return average of both

Time Complexity:
O(n + m) in worst case (merge all elements)
Efficient for small inputs or interview brute-force
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int n1 = n + m;
        int index2 = n1 / 2;
        int index1 = index2 - 1;

        int i = 0, j = 0, cnt = 0;
        int ind1 = -1, ind2 = -1;

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                if (cnt == index1) ind1 = a[i];
                if (cnt == index2) ind2 = a[i];
                i++;
            } else {
                if (cnt == index1) ind1 = b[j];
                if (cnt == index2) ind2 = b[j];
                j++;
            }
            cnt++;
        }

        while (i < n) {
            if (cnt == index1) ind1 = a[i];
            if (cnt == index2) ind2 = a[i];
            i++;
            cnt++;
        }

        while (j < m) {
            if (cnt == index1) ind1 = b[j];
            if (cnt == index2) ind2 = b[j];
            j++;
            cnt++;
        }

        if (n1 % 2 == 1) return ind2;
        return (double)(ind1 + ind2) / 2.0;
    }
};