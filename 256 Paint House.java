/*

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red;costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note: All costs are positive integers.

*/

//C++版本，直接在cost上改，不需要额外的空间了。
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n==0) return 0;
        for(int i=1; i<n; ++i){
            for(int j=0; j<3; ++j){
                costs[i][j] += min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
            }
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};

public class Solution {
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0) {
            return 0;
        }

        int[][] dp = new int[costs.length][3];//dp可以压缩成int dp[3]

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        //第i处涂一种颜色，需要由i-1处涂其他两种颜色的dp值得来
        for (int i = 1; i < costs.length; i++) {
            dp[i][0] = costs[i][0] + Math.min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = costs[i][1] + Math.min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = costs[i][2] + Math.min(dp[i - 1][0], dp[i - 1][1]);
        }

        return Math.min(dp[costs.length - 1][0], Math.min(dp[costs.length - 1][1], dp[costs.length - 1][2]));
    }
}