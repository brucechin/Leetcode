/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

//backtrack的又一题
class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p ;
        helper(nums,p);
        return result;
    }
    
    void helper(vector<int>& nums,vector<int> order){
        if(nums.size() == 0){
            result.push_back(order);
            return ;
        }
        int s = nums.size();
        for(int i=0;i<s;i++){
            // vector<int> tmp = vector<int>(nums);
            // order.push_back(tmp[i]);
            // tmp.erase(tmp.begin()+i);
            // helper(tmp,order);
            // order.pop_back();
            order.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(nums,order);
            nums.insert(nums.begin()+i,order[order.size()-1]);
            order.pop_back();
            
        }
    }
};