/*

Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.

*/


/*
Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the
 other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate)
forms a pair: left | right | candidate. 2) same for checking the right side of current word: candidate | left | right.

*/

 class Solution {
 public:
     vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string, int> dict;
         vector<vector<int>> ans;
         // build dictionary
         for(int i = 0; i < words.size(); i++) {
             string key = words[i];
             reverse(key.begin(), key.end());
             dict[key] = i;
         }
         // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }

         for(int i = 0; i < words.size(); i++) {
             for(int j = 0; j < words[i].size(); j++) {
                 string left = words[i].substr(0, j);
                 string right = words[i].substr(j, words[i].size() - j);

                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }

                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.push_back({dict[right], i});
                 }
             }
         }

         return ans;        
     }

     bool isPalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }

 };