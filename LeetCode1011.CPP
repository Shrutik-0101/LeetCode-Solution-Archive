/*
Procedure:
Find the minimum capacity of a ship to deliver all packages in exactly days.

Key Concepts:
Use Binary Search between:
low = max(weights) (can’t split packages)
high = sum(weights) (one trip)
For each capacity guess (mid), check how many days it would take using findDays.

findDays Function:
Simulates shipping with given cap.
If adding a package exceeds capacity, start a new day.
Count total days needed.

Binary Search Logic:
If it fits in ≤ days, try smaller capacity.
Else, increase capacity.

Why This Works:
The number of days needed decreases as capacity increases → perfect for binary search.
*/

class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for(int i = 0;i<weights.size(); i++){
            if(weights[i] + load > cap){
               days += 1;
                load = weights[i]; 
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            int n = findDays(weights, mid);
            if(n <= days){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};