/*

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

*/

//与longest common substring有点像的思想，判断s1的前i个和s2的前j个是否与s3的前i+j个相等，记录在dp[i+1][j+1]上

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = true;
                } else if (i == 0) {
                    dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
                } else {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]) ||
                               dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};