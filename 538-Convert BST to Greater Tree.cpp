//倒着中序遍历
class Solution {
public:
    int sum = 0;
    void travel(TreeNode* root){
        if(!root) return;
        travel(root->right);
        sum += root->val;
        root->val = sum;
        travel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};
