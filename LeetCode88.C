/*
Idea:
Start filling from the end of nums1 (which has enough space).
Use two pointers from the end of both arrays to avoid overwriting elements.

Key Steps:
Set pointers:
i = m - 1 (end of meaningful elements in nums1)
j = n - 1 (end of nums2)
k = m + n - 1 (end of total nums1 space)

While i >= 0 and j >= 0:
Place larger of nums1[i] or nums2[j] at nums1[k]
Move corresponding pointer and decrement k
After loop, if j >= 0, copy remaining nums2 into nums1
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}