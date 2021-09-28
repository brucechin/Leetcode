/*

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

*/

class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
};