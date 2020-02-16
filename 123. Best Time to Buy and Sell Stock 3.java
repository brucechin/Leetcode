/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
    //针对允许K次交易的最大获利通用解法
    // int maxProfit_Ktxn(vector<int> &prices) {
    //     // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
    //     // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
    //     //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
    //     // f[0, ii] = 0; 0 times transation makes 0 profit
    //     // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
    //     if (prices.size() <= 1) return 0;
    //     else {
    //         int K = 2; // number of max transation allowed
    //         int maxProf = 0;
    //         vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
    //         for (int kk = 1; kk <= K; kk++) {
    //             int tmpMax = f[kk-1][0] - prices[0];
    //             for (int ii = 1; ii < prices.size(); ii++) {
    //                 f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
    //                 tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
    //                 maxProf = max(f[kk][ii], maxProf);
    //             }
    //         }
    //         return maxProf;
    //     }
    // }
}