/*
Process:
This function performs binary search on a rotated sorted array to find the index of the target element.
Arr is a rotated sorted array of size n.
The array is divided into two sorted halves in each iteration.
The condition arr[low] <= arr[mid] checks if the left half is sorted.
If target lies within this left sorted half, search left.
Otherwise, search in the right half.
Else, the right half is sorted.
If the target lies in the right sorted half, search right.
Otherwise, search left.
If target is found at any point, its index is returned.
If not found, function returns -1.
*/

int search(int* arr, int n, int target) {
    int low = 0, high = n - 1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                    low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
