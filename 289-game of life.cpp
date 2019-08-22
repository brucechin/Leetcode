/*

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        
		/// iterate over the cells. because we do this inplace
		/// we have to keep the old state and the new state on the
		/// board simultanously until we are done
		/// since the board only stores values 0 and 1 this can be done easily
		/// with the following  table:
	    ///  value | alive next | alive now
	    /// -------+------------+------------
		///    0   |     0      |      0
		///    1   |     0      |      1
		///    2   |     1      |      0
		///    3   |     1      |      1
		///
		/// so basically all we have to do is add 2 to the value of cells
		/// that become alive and when determining the current neighbor
		/// count of live cells use the first bit (i.e. %2) which is kept intact
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                int live_count = 0;
                
				/// iterate over the neighbors
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
					    /// sanity checks skip this coordinate if any fail
                        if(i == 0 && j == 0 
                          || x + i < 0 
                          || y + j < 0
                          || x + i >= board.size()
                          || y + j >= board[0].size()
                          ) continue;
                        
						/// check the first bit (i.e. current state value)
						/// if non-zero (i.e. 1) increment the live count
                        if(board[x+i][y+j] % 2) live_count++;
                    }
                }
                
				/// update the next state with the rules provided
				/// dead as the next state is default so only update if the cell stays alive or becomes alive
                if((live_count == 2 || live_count == 3) && board[x][y] == 1) board[x][y]+=2;
                if(live_count == 3 && board[x][y] == 0) board[x][y]+=2; 
            }
        }
        
		/// update the board to reflect the next computed state
		/// as current, according to above values less than 2 are dead 
		/// bit-shift by 1 to the right can work here too
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                board[x][y] = board[x][y] < 2 ? 0 : 1;
            }
        }
    }
};