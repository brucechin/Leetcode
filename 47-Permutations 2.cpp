/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

//先排序，然后backtrack/dfs的时候每种数字只用一次（后面的都跳过）

class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& used, vector<int>& curr, vector<vector<int>>& res){
        if(curr.size() == nums.size()) res.push_back(curr);
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                curr.push_back(nums[i]);
                used[i] = 1;
                dfs(nums, used, curr, res);
                used[i] = 0;
                curr.pop_back();
                while((i + 1) < nums.size() && nums[i + 1] == nums[i]) i++; // skip the same element
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used(nums.size(), 0);
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, used, curr, res);
        return res;
    }
    
};