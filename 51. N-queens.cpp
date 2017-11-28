/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

*/

n = 13
count = 0

def DFS(row, shu, pie, na):
    global count
    available = ((1 << n) - 1) & ~(shu | pie | na)  # 当前行还能放置皇后的列
    while available:                                # 枚举可用的列
        p = available & -available
        available ^= p
        if row == n - 1:
            count += 1
        else:
            DFS(row + 1, shu | p, (pie | p) >> 1, (na | p) << 1) # 设置标记并移位

DFS(0, 0, 0, 0)