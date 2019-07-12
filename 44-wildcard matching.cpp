/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

*/


class Solution {
    public:
        bool isMatch(string s, string p) {
            int i = 0, j = 0, iStar = -1, jStar = -1;
            while (i < s.size()) {
                if (s[i] == p[j] || p[j] == '?') {
                    ++i; ++j;
                }else if (p[j] == '*') {
                    iStar = i;
                    jStar = j++;
                } else if (iStar >= 0) {
                    i = ++iStar;
                    j = jStar + 1;
                } else return false;
            }
            while (j < p.size() && p[j] == '*') ++j;
            return j == p.size();
        }
};