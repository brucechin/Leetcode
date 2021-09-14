/*

You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100


*/

vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
vector<int> pathsWithMaxScore(vector<string>& board) {
    auto sz = board.size();
    vector<vector<int>> score(sz + 1, vector<int>(sz + 1)), paths(sz + 1, vector<int>(sz + 1));
    board[0][0] = board[sz - 1][sz - 1] = '0';
    paths[0][0] = 1;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            if (board[i - 1][j - 1] == 'X') 
                continue;
            for (auto d : dirs) {
                auto i1 = i - d[0], j1 = j - d[1];
                auto val = score[i1][j1] + (board[i - 1][j - 1] - '0');
                if (score[i][j] <= val && paths[i1][j1] > 0) {
                    paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[i1][j1]) % 1000000007; 
                    score[i][j] = val;
                }
            }
        }
    }
    return {paths[sz][sz] ? score[sz][sz] : 0, paths[sz][sz]};
} 
