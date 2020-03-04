/*

Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,

T is "ece" which its length is 3.

*/

int lengthOfLongestSubstring(string s){
    vector<int> count(256, 0);
    int i  = 0, numDistinct = 0, maxLen = 0;
    for(int j = 0; j < s.size(); ++j){
        if(count[s[j]] == 0) numDistinct++;

        count[s[j]]++;

        while(numDistinct > 2){
            count[s[i]]--;
            if(count[s[i]] == 0) numDistinct--;

            i++;
        }
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}