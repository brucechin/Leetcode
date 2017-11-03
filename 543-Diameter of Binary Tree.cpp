class Solution {
public:
    int length = 0;
    int depth(TreeNode* root){
        if(!root) return 0;
        int left = depth(root->left),right = depth(root->right);
        length = max(left+right,length);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return length;
    }
};
