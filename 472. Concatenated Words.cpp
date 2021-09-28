/*

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
 

Constraints:

1 <= words.length <= 104
0 <= words[i].length <= 1000
words[i] consists of only lowercase English letters.
0 <= sum(words[i].length) <= 105

*/


//So, we can use a vector<int> dp(n+1) to store if w.substr(0, i) can be formed by existing words. Once i reach to n and it is not the word itself, we put the word to results.


vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n+1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;
                for (int j = i+1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j-i))) dp[j] = 1;
                }
                if (dp[n]) { res.push_back(w); break; }
            }
        }
        return res;
    }
