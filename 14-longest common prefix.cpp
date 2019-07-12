/*
题目描述
给定一个字符串(string)数组，要求返回所有字符串的最长公共前缀。

样例
给定字符串数组 ["aaca", "aacb", "aaba"] ，返回最长公共前缀 "aa"。
算法
(暴力枚举) O(n∗minLength)O(n∗minLength)
暴力枚举方法很简单：先找到所有字符串的最短长度minLength，然后从长度1到minLength依次枚举判断是否所有字符串的前缀是否都相等。

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int min_length = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
            min_length = min(min_length, int(strs[i].length()));

        for (int s = 1; s <= min_length; s++) {
            char c = strs[0][s - 1];
            for (int i = 1; i < strs.size(); i++)
                if (strs[i][s - 1] != c)
                    return strs[0].substr(0, s - 1);
        }
        return strs[0].substr(0, min_length);
    }
};
