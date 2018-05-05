/*

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

*/
//DP解法

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result(target+1,0);
        result[0] = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=target;i++){
            for(int j=0;j<size;j++){
                if(nums[j] > i){
                    break;
                }else if(nums[j] == i){
                    result[i] += 1;
                }else{
                    result[i]+= result[i-nums[j]];
                }
            }
            //cout << i << " "<<result[i]<<endl;
        }
        return result[target];
    }
};