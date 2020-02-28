/*

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"

*/

//beautiful algorithm  just add some comments 
class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;  // rs means reverse str of s;
        std::reverse(rs.begin(), rs.end());
        string mirror = s + "#" + rs;  // so if the s is aacecaaa the mirror is like               aacecaaa#aaacecaa
        //now we run kmp algorithm on mirror we will get next fun of mirror, so mirror is just like a pattern in kmp algorithm
        vector<int> next(mirror.size(),0);
        next[0] = 0;//this is really not needed, because we have init all next to 0, here we just set first character's next 0
        for(int i = 1, k = 0; i < mirror.size(); i++){
            while(k > 0 && mirror[k] != mirror[i]){ //if the suffix mismatch the preffix, we set k back just like AC goto fun
                k = next[k-1];
            }
            if(mirror[k] == mirror[i]){   // here suffix match preffix ,so we add k++
                k++;
            }
            next[i] = k;
        }
        //when we finish the next, we will get like below
        //string = a a c e c a a a # a a a c e c a a
        //next   = 0 1 0 0 0 1 2 2 0 1 2 2 3 4 5 6 7
        // this is just the next index of character of kmp 
        //if you can not understand this see here
        //http://www.cnblogs.com/c-cloud/p/3224788.html 
        //the last character's next is all we need
        int matchnums = next[mirror.size()-1];
        int mismatch = rs.size() - matchnums;
        string misstr = rs.substr(0,mismatch);
        return misstr + s;
    }
};