/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

//把该vector平分两份，其中必有一份是fully sorted的，用这一份的最小最大值来判断target是否在该份中，不在的话一定在另一半份中，依然是binary search，只是判断条件更多了。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;  // to avoid integer overflow
            if(nums[mid]==target) return mid;
            if(nums[mid]<=nums[h]){    // right half is sorted
                if(nums[mid]<target && target<=nums[h])
                    l=mid+1;  // searching in right sorted array
                else
                    h=mid-1;  // searching in left sorted array
            }
            else{   // left half is sorted
                if(nums[l]<=target && target<nums[mid])
                    h=mid-1;  // searching in left sorted array
                else
                    l=mid+1;  // searching in right sorted array
            }
        }
        return -1;
    }
};