class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        return root;
    }
};
