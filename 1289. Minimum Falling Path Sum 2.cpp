/*

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n = arr.size() ;
        vector<int> dp ;
        dp = arr[n-1] ;
        
        for(int i=n-2;i>=0;i--){
            int firstmin=INT_MAX,secondmin=INT_MAX,firstminindex ;
            for (int j=0;j<n;j++){
                if (firstmin>dp[j]){                    //calculating first min
                    firstmin = dp[j] ;
                    firstminindex = j ;
                }
            }for (int j=0;j<n;j++){
                if (j==firstminindex)continue ;                          //second min
                secondmin = min(secondmin,dp[j]) ;
            }
            for (int j=0;j<n;j++){
                if (j==firstminindex) dp[j]=arr[i][j]+secondmin ;  
                else dp[j] = arr[i][j]+firstmin ;
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};
