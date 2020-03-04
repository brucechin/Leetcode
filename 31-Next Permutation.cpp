/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

//基本思路是把大数往前提，之后再将后面的元素字典序变最小。
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k = -1, l = 0, i = 0;
        for (i = len - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                k = i; break;//nums[k + 1]到end部分都是逆序的
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end()); // 已经是逆序，直接翻转
            return ;
        }
 
        for (i = len - 1; i >= 0; --i) {
            if (nums[i] > nums[k]) {
                l = i; break;//nums[k]与后面逆序的序列里倒着数第一个比nums[k]大的第一个交换
            }
        }
        swap(nums[k], nums[l]); // 交换元素位置
        reverse(nums.begin() + k + 1, nums.end()); // 此时nums[k]之后还是完全倒序的，整体反转之后是最小的排列，得到了下一个全排列
    }
};

