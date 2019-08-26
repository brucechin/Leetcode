/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


class Solution {
public:
    int numTrees(int n) {
        int record[n + 1];
        record[0] = 1;
        record[1] = 1;
        for(int i = 2; i <= n; i++){
            int r = 0;
            for(int j = 0; j < i; j++){
                r += record[j] * record[i - j - 1];
            }
            record[i] = r;
        }
        return record[n];
    }
};