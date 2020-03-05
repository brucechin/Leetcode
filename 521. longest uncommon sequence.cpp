/*

给定两个字符串，你需要从这两个字符串中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。

示例 :

输入: "aba", "cdc"
输出: 3
解析: 最长特殊序列可为 "aba" (或 "cdc")
说明:

两个字符串长度均小于100。
字符串中的字符仅含有 'a'~'z'。
*/

bool cmp(pair<string,int> &a, pair<string,int> &b)
{
    return a.first.size() > b.first.size();
}

bool isS1subsOfS2(string &s1, string &s2){
    int j = 0, i = 0;
    for(; i < s1.size(); ++i){
        while(j < s2.size() && s1[i] != s2[j]) ++j;
        if(j == s2.size())
           return false;
        ++j;
    }
    return true;
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> m;
        for(int i = 0; i < strs.size(); ++i)
          ++m[strs[i]];
        vector<pair<string,int>> v;
        for(auto it = m.begin(); it != m.end(); ++it)
           v.push_back(*it);
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size(); ++i)
        {
           if(v[i].second == 1){
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(v[i].first,v[j].first))
                     break;
               if(j == i) return v[i].first.size();
           }
        }
        return -1;
    }
};
