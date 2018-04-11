/*

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

*/

//bit operation

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitwords;
        for(int i=0; i<words.size() ;i++){
            int bitword = 0;
            for(int j=0; j<words[i].size(); j++){
                bitword |= 1 << words[i][j] - 'a';
            }
            bitwords.push_back(bitword);
        }
        int maxProd = 0;
        for(int i=0; i< bitwords.size();i++){
            for(int j=0; j<bitwords.size();j++){
                if(i == j) continue;
                int tmp1 = bitwords[i]&bitwords[j];
                if(tmp1 == 0){
                    int tmp2 = words[i].size() * words[j].size();
                    maxProd = max(maxProd,tmp2);
                }
            }
        }
        return maxProd;   
    }
};