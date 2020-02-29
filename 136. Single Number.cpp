/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        //perform XOR operation on elements
        //this will leave the result as the only number which is
        //not repeated as The result of XOR is 1 if the two bits are different.
        //initialize the value with 0
        int result = 0; 
        
        for(auto value : nums)
        {
            result ^= value;
        }

        return result;
    }
};