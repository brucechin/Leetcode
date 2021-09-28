
/*

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104

*/

/*---------------------------------------------------------------

You can solve this problem in this way :

let's suppose the values are given as...
[2,3]
[4,6]
[3,7]
[4,8]

If we Sort this envelopes in a tricky way that Sort the envelopes according to width BUT when the values of height are same, we can sort it in reverse way like this :

[2,3]
[3,7]
[4,8]
[4,6]

Now just Do LIS on the all height values, you will get the answer
当width相同，height要从高到低，不然求LIS的时候，可能width相同，height能有多个可以fit的结果，这样可以保证相同width下选唯一一个最小的满足大于上个width下height的height。
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<vector<int>>& e = envelopes;
        
        sort(e.begin(), e.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        int n = e.size();
        
        vector<int> dp(n, 1);
        
        int ans = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (e[i][1] > e[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};