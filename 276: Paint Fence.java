/*

There is a fence with n posts, each post can be painted with one of the k colors. You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

*/

public class Solution {
    public int numWays(int n, int k) {
        if (n <= 0 || k <= 0) {
            return 0;
        }
         
        if (n == 1) {
            return k;
        }
         
        int preSame = 0;
        int preDiff = k;
         
        for (int i = 1; i < n; i++) {
            int same = preDiff;
            int diff = (k - 1) * (preSame + preDiff);
             
            preSame = same;
            preDiff = diff;
        }
         
        return preSame + preDiff;
    }
}