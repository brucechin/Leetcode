/*

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8
 

Constraints:

1 <= steps <= 500
1 <= arrLen <= 106

*/

int numWays(int steps, int arrLen) {
    int sz = min(steps / 2 + 1, arrLen);
    vector<int> v1(sz + 2), v2(sz + 2);
    v1[1] = 1;
    while (steps-- > 0) {
        for (auto i = 1; i <= sz; ++i)
            v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007; //下一步中位置i可能由i-1, i, i+1三个位置移动过来的
        swap(v1, v2);
    }
    return v1[1];
}