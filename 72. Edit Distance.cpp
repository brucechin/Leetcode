/*

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/


//这个是dp数组压缩成一维的最优解
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> dp(n1 + 1, 0);
        for(int i = 0; i <= n1; ++i)
            dp[i] = i;

        for(int j = 1; j <= n2; ++j)
        {
            /* dp[0]等价与dp[0][j - 1] */
            int prev = dp[0];
            dp[0] = j;
            for(int i = 1; i <= n1; ++i)
            {
                /* 此时的dp[i]等价于dp[i][j - 1]，将其赋值给prev
                 * 在下次循环时，prev就代表dp[i - 1][j - 1]
                 * 因为i增加了，此时的i就变为i-1了  */
                int temp = dp[i];
                if(word1[i - 1] == word2[j - 1])
                    dp[i] = prev;
                else
                    /* 此时的dp[i]等价于dp[i][j - 1]，而dp[i - 1]等价于dp[i - 1][j] */
                    /* prev等价于dp[i - 1][j - 1]，因为prev中的i是此时的i - 1 */
                    dp[i] = 1 + std::min(prev, std::min(dp[i], dp[i - 1]));
                prev = temp;
            }
        }
        return dp[n1];
    }
};