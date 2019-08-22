/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

 */


//better solution than the second one due to less vector insert and remove operations
class Solution {
public:
    vector<vector<int>> result;
    void genrateCombinations(int &n, int &k, vector<int> &op, int indx) {   
        if (op.size() == k) {
            result.push_back(op);
            return;
        }
        
        for (int i = indx; i <= n; i++) {
            op.push_back(i);
            genrateCombinations(n, k, op, i + 1);
            op.pop_back();
        }        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>op;  
        genrateCombinations(n, k, op, 1);
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<int> r;
        for(int i = 0; i < n; i++){
            nums.push_back(i + 1);
        }
        helper(nums, r, k);
    }

    void helper(vector<int> nums, vector<int> r, int k){
        if(k == 0){
            res.push_back(r);
            return;
        }
        
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int t = nums[0];
            r.push_back(t);
            nums.erase(nums.begin());
            helper(nums, r, k - 1);
            r.pop_back();
        }
    }
};



