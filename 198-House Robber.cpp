/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 money you can rob tonight without alerting the police.

*/

/*

简单的动态规划问题

*/

/*
O(n)空间的解法
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        vector<int> sum(size,0);
        sum[0] = nums[0];
        sum[1] = max(nums[0],nums[1]);
        for(int i=2; i<size; i++){
            sum[i] = max(sum[i-1],sum[i-2]+nums[i]);
        }
        return sum[size-1];
    }
};

/*
O(1)空间的解法，但稍微慢一点
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size(),tmp;
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        int left = nums[0],right = max(nums[0],nums[1]);
        for(int i=2; i<size; i++){
            tmp = max(right,left+nums[i]);
            left = right;
            right = tmp;
        }
        return right;
    }
};
