/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

/*

相较版本1，更新DP的vector时，如果遇到obstacle，则出发点到该点的路径为0种。
此外初始化方面也稍作改变，版本一中直接把,m*1的grid中到达所有点的路径数直接设为1，但在本题中，我只把起点处设为1（当起点处是0时），其余m*n-1个点都需要遍历

*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> result(m+1,0);
        if(obstacleGrid[0][0] == 0) result[1] = 1;
        for(int i=0; i<n; i++){
            for(int j=1; j<m+1; j++){
                if(obstacleGrid[j-1][i] == 1)
                    result[j] = 0;
                else
                    result[j] = result[j-1] + result[j];
            }
        }
        return result[m];
        
    }
};