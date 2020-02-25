/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*/

//重点是要从两边各扫一次。。刚开始做的时候忘记从右边扫左边了，以count==0时要更新一次最大值，count<0的时候放弃之前的substring从当下开始算起

class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int start = -1;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == ')'){
                count--;
            }else{
                count++;
            }
            
            if(count < 0){
                count = 0;
                start = i;
            }else if(count == 0){
                res = max(res, i - start);
            }
            
        }
        
        count = 0;
        start = s.size();
        for(int i = s.size() - 1; i > 0; i--){
            
            if(s[i] == '('){
                count--;
            }else{
                count++;
            }
            
            if(count < 0){
                count = 0;
                start = i;
            }else if(count == 0){
                res = max(res, start - i);
            }
            
        }
        
        return res;
    }
};