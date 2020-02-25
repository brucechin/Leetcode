/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) return true;
        return false;
    }
private:
    int m;
    int n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
        if (k == word.length() - 1) return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};