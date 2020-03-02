/*

A chess knight can move as indicated in the chess diagram below:

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.


Example 1:

Input: 1
Output: 10
Example 2:

Input: 2
Output: 20
Example 3:

Input: 3
Output: 46
 

Note:

1 <= N <= 5000

*/

class Solution
{
    static const int MOD = 1000000007;

public:
    int knightDialer(int N)
    {
        vector<long> cur(10, 1), next(cur);
        for (int i = 2; i <= N; ++i)
        {
            next[0] = (cur[4] + cur[6]) % MOD;
            next[1] = (cur[6] + cur[8]) % MOD;
            next[2] = (cur[7] + cur[9]) % MOD;
            next[3] = (cur[4] + cur[8]) % MOD;
            next[4] = (cur[0] + cur[3] + cur[9]) % MOD;
            next[5] = (0);
            next[6] = (cur[0] + cur[1] + cur[7]) % MOD;
            next[7] = (cur[2] + cur[6]) % MOD;
            next[8] = (cur[1] + cur[3]) % MOD;
            next[9] = (cur[2] + cur[4]) % MOD;
            cur.swap(next);
        }
        return accumulate(cur.begin(), cur.end(), 0L) % MOD;//0L是long类型的0，防止溢出
    }
};