/*

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum % k != 0 || k <= 0) return false;
        vector<int> visited(nums.size(), 0);
        return partition(nums, visited, 0, k, 0, target);
    }

    bool partition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int target) {
        if(k == 1) return true;
        if(cur_sum > target) return false;
        if(cur_sum == target) return partition(nums, visited, 0, k - 1, 0, target);

        for(int i = start_index; i < nums.size(); i++){
            if(visited[i] == 0){
                visited[i] = 1;
                if(partition(nums, visited, i + 1, k, cur_sum + nums[i], target)) return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};