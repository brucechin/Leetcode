/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next greater number
        int i = nums.size() - 1;
        for(; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                helper(nums, i - 1);
                return;
            }
        }
        if(i == 0){
            reverse(nums.begin(), nums.end());
        }
    }
    
    void helper(vector<int>& nums, int start){
        int end = nums.size() - 1;
        while(end > start){
            if(nums[end] > nums[start]){
                swap(nums, start, end);
                reverse(nums.begin() + start + 1, nums.end());
                break;
            }
            end--;
        }
        
    }
    
    
    void swap(vector<int>& nums, int left, int right){
        if(left < right && left >= 0 && right <= nums.size()){
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
    }
};