/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> record;
        int n = s.size(), ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(record.find(s[i]) != record.end()){
                j = max(record[s[i]] + 1, j);//如果该单词之前出现过，sliding window的start point应设为上一次出现的位置后面一位
            }
            ans = max(ans, i - j + 1);
            record[s[i]] = i;
        }
        return ans;
    }
};