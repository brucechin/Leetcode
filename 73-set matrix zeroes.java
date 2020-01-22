/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

class Solution {
    public void setZeroes(int[][] matrix) {
        if(matrix == null  || matrix.length == 0 || matrix[0].length == 0) return;
        
        int[] rows = new int[matrix.length];
        int[] cols = new int[matrix[0].length];
        
        for(int row = 0; row < matrix.length; row++){
            for(int col = 0; col < matrix[0].length; col++){
                if(matrix[row][col] == 0){
                    rows[row] = 1;
                    cols[col] = 1;
                }
            }
        }
        
        for(int row = 0; row < matrix.length; row++){
            for(int col = 0; col < matrix[0].length; col++){
                if(rows[row]== 1 || cols[col] == 1){
                    matrix[row][col] = 0;           
                }
            }
        }
    }
}