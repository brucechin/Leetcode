/*

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/
/*

题意只能删一个，那么在比对过程中出现一次不相等时，就分别跳过两个点，尝试是否能对称，有一个能对称就返回true

*/
