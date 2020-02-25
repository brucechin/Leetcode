/*

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        DFS(root1, t1);
        DFS(root2, t2);
        return t1==t2;
    }
    
    void DFS(TreeNode* root, string& s) {
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL) s+=to_string(root->val)+"#";
        DFS(root->left, s);
        DFS(root->right, s);
    }
};