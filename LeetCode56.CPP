/*
Idea:
Sort all intervals by starting time.
Iterate through and merge overlapping intervals by comparing current start with the last merged end.

Key Steps:
Sort the intervals based on start time (arr[i][0]).

Initialize empty result ans.

Loop through each interval:

If ans is empty or current start is after last merged end →
new interval, add it.

Else →
overlap, update the end of last merged interval with max(end1, end2).
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
            int n = arr.size();
            sort(arr.begin(), arr.end());
            vector<vector<int>> ans;
            for(int i = 0;i <n;i++){
                if(ans.empty() || arr[i][0] > ans.back()[1]){
                    ans.push_back(arr[i]);
                }
                else{
                    ans.back()[1] = max(ans.back()[1], arr[i][1]);                }
            }
            return ans;
    }
};