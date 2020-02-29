/*

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

*/


//We have nums=[1,2,3,4,5] and S=3 for example. There is a solution 1-2+3-4+5=3. After moving nums in negative to the right side, it becomes 1+3+5=3+2+4. 
//Each side is half of sum(nums)+S. This means we can turn this into a knapsack problem with sacks=nums and target_sum=(sum(nums)+S)/2. 
//In this example sacks=[1,2,3,4,5] and target_sum=9. [1,3,5] is one of the solutions.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
	int sum = 0;
	for (auto n : nums) sum += n;
	if ((sum % 2 + S % 2 == 1) || S > sum || S < -sum) return 0;
	int newS = (sum + S) / 2;
	vector<int> dp(newS + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = newS; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[newS];
}
};