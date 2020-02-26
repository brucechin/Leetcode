/*

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

*/

/**
 * The idea is always keep an max-product-window less than K;
 * Every time add a new number on the right(j), reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);
 * Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);
 * example:
 * for window (5, 2, 6), when 6 is introduced, it add 3 new subarray:
 *       (6)
 *    (2, 6)
 * (5, 2, 6)
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int cnt = 0;
        int pro = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j];
            while (i <= j && pro >= k) {
                pro /= nums[i++];
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};