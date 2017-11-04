/*

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

*/

/*

sliding-window法，为了减少做加法的次数，每次k个数相加，把后k-1个数相加的结果留到下次继续用

*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double tmp =0,result = INT_MIN;
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(i<k){
                tmp += nums[i];
            }else{
                result = max(result,tmp);
                tmp = tmp + nums[i] - nums[i-k];
            }
        }
        result = max(result,tmp);
        return result / k;
    }
};
