/*

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxdist = m + n;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] == 0 ? q.push(make_pair(i, j)) : (void)(matrix[i][j] = maxdist);

        int delta[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int d = 0; d < 4; d++) {
                int x1 = x + delta[d][0], y1 = y + delta[d][1];
                if (0 <= x1 && x1 < m && 0 <= y1 && y1 < n) {
                    if (matrix[x1][y1] == maxdist) q.push(make_pair(x1, y1));
                    matrix[x1][y1] = min(matrix[x1][y1], matrix[x][y] + 1);
                }
            }
        }
        return matrix;
    }
};