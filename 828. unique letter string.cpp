/*

A character is unique in string S if it occurs exactly once in it.

For example, in string S = "LETTER", the only unique characters are "L" and "R".

Let's define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ("LETTER") =  2.

Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1.
Note: 0 <= S.length <= 10000.

*/

/*

使用的是动态规划 Dynmaic Programming 的思想，用一个一维数组 dp，其中 dp[i] 表示以 S[i] 为结尾的所有子串中的单独字母个数之和，这样只要把 [0, n-1] 范围内所有的 dp[i] 累加起来就是最终的结果了。
更新 dp[i] 的方法关键也是要看重复的位置，比如当前是 AB 的话，此时 dp[1]=3，因为以B结尾的子串是 B 和 AB，共有3个单独字母。若此时再后面加上个C的话，由于没有重复出现，
则以C结尾的子串 C，BC，ABC 共有6个单独字母，即 dp[2]=6，怎么由 dp[1] 得到呢？首先新加的字母本身就是子串，所以一定是可以贡献1的，然后由于之前都没有C出现，则之前的每个子串中C都可以贡献1，
而原本的A和B的贡献值也将保留，所以总共就是 dp[2] = 1+dp[1]+2 = 6。但若新加的字母是A的话，就比较 tricky 了，首先A本身也是子串，有稳定的贡献1，由于之前已经有A的出现了，所以只要知道了之前A的位置，
那么中间部分是没有A的，即子串 B 中没有A，A可以贡献1，但是对于之前的有A的子串，比如 AB，此时新加的A不但不能贡献，反而还会伤害之前A的贡献值，即变成 ABA 了后，不但第二个A不能贡献，
连第一个A之前的贡献值也要减去，此时 dp[2] = 1+dp[1]+(2-1)-(1-0) = 4。其中2是当前A的位置，1是前一个A的位置加1，0是再前一个A的位置加1。讲到这里应该就比较清楚了吧，
这里还是要知道每个字符的前两次出现的位置，这里用两个数组 first 和 second，不过需要注意的是，这里保存的是位置加1。又因为每个 dp 值只跟其前一个 dp 值有关，所以为了节省空间，
并不需要一个 dp 数组，而是只用一个变量 cur 进行累加即可，记得每次循环都要把 cur 存入结果 res 中。那么每次 cur 的更新方法就是前一个 cur 值加上1，再加上当前字母产生的贡献值，
减去当前字母抵消的贡献值

*/

class Solution {
public:
    int uniqueLetterString(string S) {
        int res = 0, n = S.size(), cur = 0, M = 1e9 + 7;
        vector<int> first(26), second(26);
        for (int i = 0; i < n; ++i) {
            int c = S[i] - 'A';
            cur = cur + 1 + i - first[c] * 2 + second[c];
            res = (res + cur) % M;
            second[c] = first[c];
            first[c] = i + 1;
        }
        return res;
    }
};