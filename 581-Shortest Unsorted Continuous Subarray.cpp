/*

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1,right = -2, size= nums.size(),MAX = nums[0],MIN=nums[size-1];
        for(int i =1; i<size;i++){
            MAX = max(MAX,nums[i]);
            MIN =min(MIN,nums[size-i-1]);
            if(nums[i] < MAX) right = i;
            if(nums[size-i-1] > MIN) left = size - i -1;
        }
        return right-left +1;
    }
};
