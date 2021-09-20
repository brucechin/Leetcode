/*

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104

*/

int numSquares(int n) {
    static vector<int> dp {0};
    while (dp.size() <= n) {
        int m = dp.size(), squares = INT_MAX;
        for (int i=1; i*i<=m; ++i)
            squares = min(squares, dp[m-i*i] + 1);
        dp.push_back(squares);
    }
    return dp[n];
}