'''

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

'''

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        table = {0:0}#count:index
        count = 0
        max_length = 0
        for index,num in enumerate(nums,1):
            if(num == 0):
                count+=1
            else:
                count-=1
            
            if count in table:
                max_length = max(max_length,index-table[count]) #count相同说明两者之间的数组0 1个数相同
            else:
                table[count] = index
        return max_length