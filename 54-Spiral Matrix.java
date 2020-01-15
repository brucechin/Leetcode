/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/



public List spiralOrder(int[][] matrix)
{
    List output = new ArrayList();

    if (matrix.length == 0) return output;
    
    int rowStart = 0, rowEnd = matrix.length - 1;
    int colStart = 0, colEnd = matrix[0].length - 1;
    int i;
    
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        // Right
        for (i = colStart; i <= colEnd; i++)
        {
            output.add(matrix[rowStart][i]);
        }
        rowStart++;
        
        // Down
        for (i = rowStart; i <= rowEnd; i++)
        {
            output.add(matrix[i][colEnd]);
        }
        colEnd--;
        
        // Left
        if (rowStart <= rowEnd)
        {
            for (i = colEnd; i >= colStart; i--)
            {
                output.add(matrix[rowEnd][i]);
            }
        }
        rowEnd--;            
        
        // Up
        if (colStart <= colEnd)
        {
            for (i = rowEnd; i >= rowStart; i--)
            {
                output.add(matrix[i][colStart]);
            }
        }
        colStart++;
    }
    
    return output;
}