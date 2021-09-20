/*

Given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:


You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.
Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
Example 4:

Input: n = 50, m = 100, k = 25
Output: 34549172
Explanation: Don't forget to compute the answer modulo 1000000007
Example 5:

Input: n = 37, m = 17, k = 7
Output: 418930126
 

Constraints:

1 <= n <= 50
1 <= m <= 100
0 <= k <= n

*/

int dp[101][51][51] = {};
int dfs(int n, int m, int k, int i, int max_val) {
    if (n == i)
        return k == 0;
    if (k < 0)
        return 0;
    if (dp[max_val][i][k] == 0) {        
        dp[max_val][i][k] = 1;
        for (auto val = 1; val <= m; ++val) {
            dp[max_val][i][k] += dfs(n, m, k - (max_val < val), i + 1, max(max_val, val)); //n只是用来终止recursion的，m是为了一个个试， k - (max_val < val) 是更新剩余的search cost budget，i+1是更新生成的array长度，最后一个是更新当前最大值
            dp[max_val][i][k] %= 1000000007;
        }
    }
    return dp[max_val][i][k] - 1;
}
int numOfArrays(int n, int m, int k) {
    return dfs(n, m, k, 0, 0);
}
