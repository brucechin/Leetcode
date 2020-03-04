/*

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

eg : Given nums = [1, -1, 5, -2, 3], k = 3, return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

*/



class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        unordered_map<int, int> hash;//存nums里前i个数的和
        int sum = 0, Max = 0;
        hash[0] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(hash.count(sum-k)) Max = max(Max, i + 1 - hash[sum-k]);
            if(!hash.count(sum)) hash[sum] = i + 1;
        }
        return Max;
    }

}