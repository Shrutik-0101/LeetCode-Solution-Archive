/*
Procedure:
Start at the top-right cell.
If the current value is greater than the target, move left.
If less, move down.
Repeat until found or bounds exceeded.
This avoids binary search and leverages the matrix structure for an efficient solution.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};
