/*
Goal:
Rotate a square matrix 90 degrees clockwise, in-place.

Working Procedure:
Transpose the matrix
Swap matrix[i][j] with matrix[j][i] → Rows become columns.
Reverse each row
Flip every row left to right → This completes the 90° rotation.
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    // Step 1: Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}