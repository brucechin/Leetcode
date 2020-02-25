/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.

*/


//keep swapping 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int n = nums.size();

        //this for loop is only O(N) time complexity
        for (int i = 0; i < n; i++){
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) //have to keep swapping
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for (int i = 0; i < n; i++){
            if (nums[i] != i + 1) 
                return i + 1;
        }
        
        return n+1;
    }
};


class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        
        for(int i = 0;i < A.size();i++){
            if(A[i] <= 0)
                A[i] = INT_MAX;
        }
        for(int i = 0; i < A.size(); i++) { 
            if(abs(A[i])-1 < A.size()){
                if(A[abs(A[i])-1] < 0)
                    continue;
                A[abs(A[i])-1] *=-1;
            }
        } 
        for(int i = 0; i < A.size(); i++) 
            if(A[i] > 0) 
                return i + 1; 
  
        return A.size() + 1; 
    }
};