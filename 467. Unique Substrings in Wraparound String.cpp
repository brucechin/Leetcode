/*

We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Given a string p, return the number of unique non-empty substrings of p are present in s.

 

Example 1:

Input: p = "a"
Output: 1
Explanation: Only the substring "a" of p is in s.
Example 2:

Input: p = "cac"
Output: 2
Explanation: There are two substrings ("a", "c") of p in s.
Example 3:

Input: p = "zab"
Output: 6
Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of p in s.
 

Constraints:

1 <= p.length <= 105
p consists of lowercase English letters.

*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); i++) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
            letters[cur] = max(letters[cur], ++len);//只记录end是cur的他有多长的连贯string，
        }
        return accumulate(letters.begin(), letters.end(), 0);
    }
};
