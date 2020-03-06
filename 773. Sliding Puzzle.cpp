/*

On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

*/
//这个解法更通用，不用给0所在所有位置都设定好可以走的位置，走的时候判断是不是合法移动的方向。
//可以用双向BFS和启发式搜索进一步降低复杂度
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0;
        set<vector<vector<int>>> visited;
        queue<pair<vector<vector<int>>, vector<int>>> q;
        vector<vector<int>> correct{{1, 2, 3}, {4, 5, 0}};
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) q.push({board, {i, j}});
            }
        }
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                auto t = q.front().first; 
                auto zero = q.front().second; q.pop();
                if (t == correct) return res;
                visited.insert(t);
                for (auto dir : dirs) {
                    int x = zero[0] + dir[0], y = zero[1] + dir[1];
                    if (x < 0 || x >= 2 || y < 0 || y >= 3) continue;
                    vector<vector<int>> cand = t;
                    swap(cand[zero[0]][zero[1]], cand[x][y]);
                    if (visited.count(cand)) continue;
                    q.push({cand, {x, y}});
                }
            }
            ++res;
        }
        return -1;
    }
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        string target="123450",
        begin=to_string(b[0][0])+to_string(b[0][1])+to_string(b[0][2])
             +to_string(b[1][0])+to_string(b[1][1])+to_string(b[1][2]);
        
        //0在不同位置下，可以与周边交换(移动)的点位集合
        vector<vector<int>> nextMoves{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        //bfs + memorization 减少重复访问
        unordered_set<string> visited{begin};
        queue<string> q; q.push(begin);
        for (int depth=0; !q.empty(); ++depth){
            int size=q.size();
            for (int i=0; i<size; ++i){
                auto curr=q.front(); q.pop();
                if (curr==target) return depth;
                int zero=curr.find("0");
                for (auto next: nextMoves[zero]){
                    auto candidate=curr;
                    swap(candidate[zero],candidate[next]);
                    if (visited.find(candidate)==visited.end()){//visited的话说明在depth更小的时候已经访问过这个状态了，现在这条路不是步数最少抵达这个状态的
                        visited.insert(candidate);
                        q.push(candidate);
                    }
                }
            }
        }
        return -1;
    }
};