/*

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
Follow up:
Could you solve it in O(nk) runtime?

*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size(), min1, min2;
        vector<int> dp(k, 0);
        for (int i = 0; i < n; i++) {
            int premin1 = i ? min1 : 0, premin2 = i ? min2 : 0;
            min1 = min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[j] != premin1 || premin1 == premin2)
                    dp[j] = premin1 + costs[i][j];
                // pre_min1 occurred when painting house i-1 with color j, 
                // so it cannot be added to dp[j]
                else dp[j] = premin2 + costs[i][j];
                if (min1 <= dp[j]) min2 = min(min2, dp[j]);
                else min2 = min1, min1 = dp[j];
            }
        }
        return min1;
    }
};