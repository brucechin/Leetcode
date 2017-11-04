/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

// 动态规划
class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n,0);
        result[0] = 1;
        result[1] = 2;
        for(int i =2;i<n;i++){
            result[i] = result[i-1] +result[i-2];
        }
        return result[n-1];
    }
};
