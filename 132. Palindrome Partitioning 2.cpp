/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;       //act as a sentinel
        for(int i = 0; i < n; i++){
	//palindrome of length 1,3,5...
            for(int len = 0; i-len >= 0 && i+len < n && s[i-len] == s[i+len]; len++)
                dp[i+len+1] = min(dp[i+len+1], dp[i-len]+1);
	//palindrome of lenght 2,4,6...
            for(int len = 0; i-len >= 0 && i+len+1 < n && s[i-len] == s[i+len+1]; len++)
                dp[i+len+2] = min(dp[i+len+2], dp[i-len]+1);
        }
        return dp[n];
    }
};