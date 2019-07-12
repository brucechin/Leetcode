/*

题目描述
给定一个无序的整数序列，找到第一个缺失的正整数。
要求时间复杂度为 O(n)O(n)，使用常数空间。

样例
输入[1,2,0]，返回3
输入[3,4,-1,1]，返回2

算法
(桶排序) O(n)O(n) Time, O(1)O(1) Space
不用额外空间的桶排序：保证1出现在nums[0]的位置上，2出现在nums[1]的位置上，…，n出现在nums[n-1]的位置上，其他的数字不管。例如[3,4,-1,1]将被排序为[1,-1,3,4]
遍历nums，找到第一个不在应在位置上的1到n的数。例如，排序后的[1,-1,3,4]中第一个 nums[i] != i + 1 的是数字2（注意此时i=1）。
时间复杂度分析：代码中第二层while循环，每循环一次，会将一个数放在正确的位置上，所以总共最多执行 nn 次，所以总时间复杂度 O(n)O(n)。


*/


class Solution{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n
                    && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
