/*

Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.



Solution:

We use DFS + backtracking to check if the substring of pattern can be used to match there previous pattern.

In the recursion, we check if the current character has already had a mapping.

If so, we check if it can go along with this path to the end.

Otherwise, we use backtracking to put all candidate mapping of this character and check if it has its path to the end.

The end condition is that when we finish putting all character in the pattern string to the HashMap, we check if the target string has also been finished putting all its elements.

*/

public class Solution {
    
    public HashMap<Character, String> map = new HashMap<>();
    public boolean wordPatternMatch(String pattern, String str) {
        if (pattern.length() == 0) {
            return str.length() == 0;
        }
        char c = pattern.charAt(0);
        if (map.containsKey(c)) {
            String value = map.get(c);
            if (value.length() > str.length() || !str.substring(0, value.length()).equals(value)) {
                return false;
            }
            if (wordPatternMatch(pattern.substring(1), str.substring(value.length()))) {
                return true;
            }
        }
        else {
            for (int i = 1; i <= str.length(); i++) {
                String value = str.substring(0, i);
                if (map.containsValue(value)) {
                    continue;
                }
                map.put(c, value);
                if (wordPatternMatch(pattern.substring(1), str.substring(value.length()))) {
                    return true;
                }
                map.remove(c);
            }
        }
        return false;
    }
}