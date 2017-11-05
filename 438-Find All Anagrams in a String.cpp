/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

/*

sliding window解法，为了不每次判断一下整个window内count[26]都为0，选择动态维护一个数sp，其代表s内某window里还跟p有多少个字母的差别

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26,0),result;
        int sp = p.size(),ss = s.size();
        if (ss == 0 || sp == 0 || s.length() < p.length())
            return result;
        for(int j = 0; j< sp; j++){
            count[p[j] - 'a']++;
        }
        int start =0,end =0;
        while(end < ss){
            if(end - start == p.size() && count[s[start++] - 'a']++ >= 0)
                sp++;
            if(--count[s[end++] - 'a'] >= 0) //小于0说明是window内相对p多余的字母，移入或移出window不影响sp
                sp--;
            if(sp == 0)
                result.push_back(start);
        }
        return result;
    }
};
