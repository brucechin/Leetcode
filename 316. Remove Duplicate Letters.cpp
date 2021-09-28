/*

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/


//把vector当成stack用，因为result必须得是input的一个subsequence。
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> visited;
        unordered_map<char, int> counter;
        string result = "";
        for (auto c : s) counter[c]++;
        for (auto c : s) {
            counter[c]--;
            if (visited[c]) continue;  
            while (!result.empty() && c < result.back() && counter[result.back()] > 0) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result;
    }
};