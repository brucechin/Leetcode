/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

// dp + 空间复杂度压缩

// 可以进一步压缩，直接在grid上记录当前点到终点的最小距离
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size()+1,0);
        for(int i=grid[0].size()-1;i>=0;i--){
            result[i] += result[i+1] + grid[grid.size()-1][i];
        }
        result[grid[0].size()] = 1000000;
        for(int i=grid.size()-2;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                result[j] = result[j+1] < result[j] ? result[j+1] + grid[i][j] : result[j] + grid[i][j];
            }
        }
        return result[0];
    }
};