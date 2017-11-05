/*



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
