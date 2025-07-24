/*
Goal: Find all combinations of numbers (can repeat) that add up to a target.

Approach Summary:
Use backtracking to explore all possible number combinations.
At each step, try picking a number and subtract it from the target.
If the target becomes zero, save the combination.
If the target becomes negative, stop (invalid path).
Continue trying from the current number onward (to allow reuse).
Backtrack by removing the last added number before trying a new one.

Trick to Remember:
Pick → Try → Backtrack
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(candidates, target, 0, comb, res);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, comb, res);
            comb.pop_back();
        }
    }
};