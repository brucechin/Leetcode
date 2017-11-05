/*

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

*/

/*

l is the length of single direction Longest-Univalue-Path start from left-child,
r is the length of single direction Longest-Univalue-Path start from right-child,
resl is the length of single direction Longest-Univalue-Path start from parent go left,
resr is the length of single direction Longest-Univalue-Path start from parent go right.
int dfs(node) returns the Longest-Univalue-Path-Start-At that node, and update the result of Longest-Univalue-Path-Across that node through side effect.
It is really hard to name those variables to reflect these concept.

因为会出现一个节点两侧相同值的节点连在一起成为最长的，所以lup=max(l,r)，但dfs返回值是max(resl,resr)供上一层的父节点继续作比较

一旦子父节点相同这个关系断了，就得清零，不过曾经出现的最长长度已经记录在lup上了

*/


class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
