/*

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for(auto num : nums) 
            sum += num;
        if(sum %2) return false;
        return dfs(nums, 0,  sum/2);
    }
    
    bool dfs(vector<int>& nums, int start, int target){
        if( target ==0) return true;
        if(start == nums.size()) return false;
        if(nums[start] > target) return false;
        for(int i= start; i<nums.size(); i++) {
            if(nums[i]>target) break;
            if(dfs(nums, i+1, target - nums[i])) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int half = sum >> 1;
        
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;    // '0' is always reachable
        //For all num in nums, check the accessibility from half - num to 0. 
        //If 'i' is accessible by former numbers, then 'i + num' is also accessible. (DP Algorithm)
        for(auto num : nums) 
       //Below here we must start from 'half' downto 'num', otherwise current 'num' might be multiply used. 
       //e.g.: If num == 2, then we will have 2, 4, 6... will all be accessible and lead to wrong answer. 
            for(int i = half; i >= num; i--){
                //if half is too large, it takes much longer time to finish.
                if (accessibility[i - num] == true){
                    accessibility[i] = true;
                }
            }
        return accessibility[half];
    }
};