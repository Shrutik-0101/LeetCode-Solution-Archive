/*
Procedure:
Find the minimum speed needed to finish all tasks (or eat all piles) within h hours.

Key Concepts:
Binary Search on speed (low = 1, high = max(pile)).
For each speed, calculate total hours needed.
If total hours ≤ h, try a smaller speed.
Else, increase speed.

*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;
        for(int i = 0; i < v.size(); i++) {
            totalH += (v[i] + hourly - 1) / hourly;  // ceiling division
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
        int high = *max_element(v.begin(), v.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;  // to avoid overflow
            long long totalH = calculateTotalHours(v, mid);
            if(totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
