/*
Binary search is applied on columns, not on the full matrix.
In each column, find the maximum row (like finding a potential vertical peak).
Check if this candidate is greater than its horizontal neighbors.
If not, move to the direction of the bigger neighbor.
This gives you a logarithmic time search: O(n log m), much faster than brute-force O(n*m).
*/

class Solution {
public:
    int find_max(vector<vector<int>>& mat, int n, int m, int col) {
        int maxv = -1;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxv){
                maxv =  mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int max_row = find_max(mat, n ,m ,mid);
            int left = mid - 1 >= 0 ? mat[max_row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[max_row][mid + 1] : -1;
            if(mat[max_row][mid] > left && mat[max_row][mid] > right){
                return {max_row, mid};
            }
            else if(mat[max_row][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};