/*

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int len=s1.size();
		vector<int> dic1(26);
		vector<int> dic2(26);
		for(auto x:s1){
			dic1[x-'a']+=1;
		}
		int start=0; 
		for(int i=0;i<s2.size();i++){

			if(i>=len){
				dic2[s2[start]-'a']-=1;
				start++;
			}
			dic2[s2[i]-'a']+=1;

			if(dic1==dic2) return true;
		}
		return false;
	}
};