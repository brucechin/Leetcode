'''
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
'''

#带括号相关的问题都可以用栈来解决

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        stack.append(["",1])#初始化
        num = ""
        for ch in s:
            if(ch.isdigit()):
                num += ch
            elif(ch == '['):
                stack.append(["",int(num)])#前者是转换后的string记录，后者代表这段string要重复多少次
                num = ""
            elif(ch == ']'):
                content, k = stack.pop()
                stack[-1][0] += k * content
            else:
                stack[-1][0] += ch
        return stack[0][0]