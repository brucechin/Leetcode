/*

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

*/

//DP解决

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> result(size,vector<int>(size,0));
        for(int i=size-1;i>=0;i--){
            result[i][i] =1;
            for(int j=i+1;j<size;j++){
                if(s[i] == s[j]){
                    result[i][j] = result[i+1][j-1] + 2;
                }else{
                    result[i][j] = max(result[i][j-1],result[i+1][j]);
                }
                //cout << result[i][j]<<endl;
            }
        }     
        return result[0][size-1];
    }
};