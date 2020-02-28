/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int array_size = nums.size();
        int candidate1, candidate2;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < array_size; i ++){
            if(nums[i] == candidate1) count1 ++;
            else if(nums[i] == candidate2) count2 ++;
            else{
                if(count1 && count2) {count1 --; count2 --;}
                else if (count1){candidate2 = nums[i]; count2 = 1;}
                else {candidate1 = nums[i]; count1 = 1;}
            }
        }
        vector<int> candidate;
        if(count1 > 0) candidate.push_back(candidate1);
        if(count2 > 0) candidate.push_back(candidate2);
        vector<int> result;
        for(int i = 0; i < candidate.size(); i ++){
            int count = 0;
            for(int j = 0; j < array_size; j ++){
                if(nums[j] == candidate[i]) count ++;
            }
            if(count > array_size/3) result.push_back(candidate[i]);
        }
        return result;
    }
};