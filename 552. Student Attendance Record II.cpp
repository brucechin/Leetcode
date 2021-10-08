/*

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
Example 2:

Input: n = 1
Output: 3
Example 3:

Input: n = 10101
Output: 183236316
 

Constraints:

1 <= n <= 105

*/

class Solution {
public:
    int dp[100001][2][3];
    int mod=1e9+7;
    int fun(int n, int absent, int late){
        if(n==0)return 1;
        if(dp[n][absent][late]!=-1)return dp[n][absent][late];
        int ans=0;
        ans+=fun(n-1, absent, 2)%mod;//case 1
        ans%=mod;
        if(absent){
            ans+=fun(n-1, absent-1, 2)%mod;//case 2
            ans%=mod;
        }
        if(late){
            ans+=fun(n-1, absent, late-1)%mod;//case 3
            ans%=mod;
        }
        return dp[n][absent][late]=ans;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return  fun(n, 1, 2);
    }
};

