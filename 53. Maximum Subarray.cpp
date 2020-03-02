/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int tmp_res = 0;
        for(int i = 0; i < nums.size(); i++){
            tmp_res += nums[i];
            tmp_res = max(tmp_res, nums[i]);
            res = max(tmp_res ,res);
        }
        return res;
    }
};

//followup是找出两个subarray，使他们sum最大

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> left<nums.size(), INT_MIN>;
        vector<int> right<nums.size(), INT_MIN>;
        int tmp_res = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            tmp_res += nums[i];
            tmp_res = max(tmp_res, nums[i]);
            left[i] = max(tmp_res ,left[i]);
        }
        tmp_res = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            tmp_res += nums[i];
            tmp_res = max(tmp_res, nums[i]);
            right[i] = max(tmp_res ,left[i]);
        }
        for(int j = 0; j < nums.size() - 1; j++){
            res = max(res, left[j] + right[j + 1]);
        }
        return res;
    }
};