/*

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

*/

/*

运用BST的性质：p,q在root两边时root为最低共同祖先，p,q都在root左边时最低共同祖先在root左边，否则在root右边.不清楚为什么最后recursion版本用时反而快一点

如果只是普通的树的话，我想找到root到p,q各自的dfs vector路径，然后比较路径得出结果

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root-> val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};//recursion solution

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur;
        }
    }
};//non-recursion solution
