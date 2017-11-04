/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

//思路就是二分法查找，找不到的话循环会退出，最后一次循环时left=right=mid，如果nums[mid] < target 返回mid+1 反之返回mid

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;

        while(left <= right){
            int mid = left + (right -left) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }

        }
        return left;
    }
};
