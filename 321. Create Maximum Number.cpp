/*

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]

*/

//创建一个比较vector<int>大小的函数，一个把两个vector<int>合并成一个最大的vector<int>的函数，一个抽取vector<int>中前k大的数组成vector返回
//遍历nums1和nums2所有的可能性
class Solution {
public:
    bool bigger(vector<int>& nums1, int pos1, vector<int>& nums2, int pos2){
        int len1 = nums1.size(), len2 = nums2.size();

        while(pos1 < len1 && pos2 < len2){
            if(nums1[pos1] != nums2[pos2])    return nums1[pos1] > nums2[pos2];
            else{
                pos1++;
                pos2++;
            }
        }

        return pos1 < len1;
    }

    // get k largest num 
    vector<int> getLargestNum(vector<int>& nums, int k){
        vector<int> res;

        for(int i = 1, len = nums.size(), pos = 0; i <= k; i++){
            int index = pos;
            for(int j = pos + 1; j < len - (k - i); j++){
                if(nums[j] > nums[index])   index = j;
            }
            res.push_back(nums[index]);
            pos = index + 1;
        }

        return res;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;

        int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
        while(i < len1 && j < len2){
            if(nums1[i] > nums2[j]) res.push_back(nums1[i++]);
            else if(nums1[i] < nums2[j])    res.push_back(nums2[j++]);
            else{
                if(bigger(nums1, i + 1, nums2, j + 1))    res.push_back(nums1[i++]);
                else res.push_back(nums2[j++]);
            }
        }

        while(i < len1) res.push_back(nums1[i++]);
        while(j < len2) res.push_back(nums2[j++]);

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> res;

        for(int l1 = 0; l1 <= len1 && l1 <= k; l1++){
            int l2 = k - l1;
            if(l2 >= 0 && l2 <= len2){
                vector<int> maxNum1 = getLargestNum(nums1, l1), maxNum2 = getLargestNum(nums2, l2);
                vector<int> localRes = merge(maxNum1, maxNum2);
                if(res.size() == 0 || bigger(localRes, 0, res, 0))   res = localRes;
            }
        }

        return res;
    }
};