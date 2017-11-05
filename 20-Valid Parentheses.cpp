/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

/*

遇到左半边的入栈，遇到右半边的，看看栈顶有没有对应的，有的话就pop出来，没有就false，最后如果栈都pop空了说明刚好对应

*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> input;
        for(char c:s){
            switch(c){
            case '(':
            case '[':
            case '{': input.push(c);break;
            case ')':
                if(input.empty() || input.top() != '(') return false;
                else input.pop();break;
            case ']':
                if(input.empty() || input.top() != '[') return false;
                else input.pop();break;
            case '}':
                if(input.empty() || input.top() != '{') return false;
                else input.pop();break;
            default :;
            }
        }
        return input.empty();
    }
};
