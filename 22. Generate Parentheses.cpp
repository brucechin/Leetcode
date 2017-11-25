/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result,"",0,0,n);
        return result;
    }
    void backtrack(vector<string>& result,string str,int open,int close,int m){
        if(str.size() == m * 2){
            result.push_back(str);
            return ;
        }
        if(open < m) backtrack(result,str+"(",open+1,close,m);
        if(close < open) backtrack(result,str+")",open,close+1,m); //关键点，有多的(需要用)来对上时才能这样调用
    }
};