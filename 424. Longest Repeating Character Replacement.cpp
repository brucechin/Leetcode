/*

Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.


*/

//sliding window method

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int start=0,end=0,maxCount=0,maxLength=0;
        int len = s.size();
        for(;end<len ;end++){
            maxCount= max(++count[s[end]-'A'],maxCount);
            while(end-start+1 > maxCount + k){
                count[s[start]-'A']--;
                start++;
            }
            maxLength = max(maxLength,end-start+1);   
        }
        return maxLength;
    }
};