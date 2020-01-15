/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

//本题关键在于按两种策略来找target的left/right most match

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        if(size == 0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(helper(nums, target, 0, size - 1, true));
        res.push_back(helper(nums, target, 0, size - 1, false));
        return res;
    }
    
    int helper(vector<int>& nums, int target, int left, int right, bool flag){
        
        int mid;
        
        while(left + 1< right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                if(flag){
                    //keep search left most target index
                    right = mid;
                }else{
                    left = mid;
                }
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        if(flag){
            if(nums[left] == target){
                return left;
            }else if(nums[right] == target){
                return right;
            }
        }else{
            if(nums[right] == target){
                return right;
            }else if(nums[left] == target){
                return left;
            }
        }  
        return -1;  
    }
    
};