/*
Goal:
If any element in the matrix is 0, set its entire row and column to 0.

Working Procedure:
Check first row and first column
If any 0 is found, remember to make the entire first row/column 0 later.
Mark rows and columns
For the rest of the matrix, if a cell is 0, mark its row and column by setting the first cell in that row and column to 0.
Update the matrix
Use the marks to set the correct rows and columns to 0.
Set the first row and column (if needed)
If they had 0 originally, set them to all 0s at the end.
*/

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    bool firstRowZero = false, firstColZero = false;

    for (int i=0; i<m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
        }
    }
    for (int j=0; j<n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
        }
    }
    for (int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for (int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            } 
        }
    }
    if(firstColZero)
    {
        for (int i=0; i<m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    if(firstRowZero)
    {
        for (int j=0; j<n; j++)
        {
            matrix[0][j] = 0;
        }
    }
}