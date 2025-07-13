/*
Each row is initialized with 1s:

For indices 1 to i - 1, update each value using:
row[j]=previous row[j−1]+previous row[j]

First and last elements of each row stay as 1.

The triangle is built row by row using only the previous row — no formula needed.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};