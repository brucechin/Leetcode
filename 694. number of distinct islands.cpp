/*

Given a non-empty 2D arraygridof 0's and 1's, an island is a group of1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:

11000
11000
00011
00011
Given the above grid map, return 1.

Example 2:

11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:

11
1
and

 1
11
are considered different island shapes, because we do not consider reflection / rotation.

Note: The length of each dimension in the givengriddoes not exceed 50.

Thoughts:

Distinct islands: island 2d coordinates sets are distinct based off its offset

*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<vector<int>>> distinctIslands;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                vector<vector<int>> island;
                if (dfs(i, j, i, j, grid, m, n, island)){
                    distinctIslands.insert(island);
                }
            }
        }
        return distinctIslands.size();
    }
private:
    int d [5]  = {0,1,0,-1,0};

    bool dfs(int i, int j, int x, int y, vector<vector<int>> & grid, int m, int n, vector<vector<int>> & island){
        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] <= 0) return false;
        grid[x][y] *= -1; //用负数表示已经visit过了
        island.emplace_back(x-i, y-j);//用到中心点的距离offset来描述形状？但这种只能支持不旋转的情况
        for(int k = 0; k < 4; k++){
            dfs(i, j, x + d[k], y + d[k + 1], grid, m, n, island);
        }

        return true;
    }

};