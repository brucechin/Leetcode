class Solution {
public:
    int sum = 0;
    int travel(TreeNode* root){
        if(!root) return 0;
        int left = travel(root->left),right = travel(root->right);
        sum += abs(left-right);
        return (left+right + root->val);
    }
    int findTilt(TreeNode* root) {

        travel(root);
        return sum;
    }
};
