/*

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

int closestValue(TreeNode* root, double target){
    return closest(root, target, root->value);
}

int closest(TreeNode* root, double target, int val){
    if(root == NULL) return val;
    if(abs(target - root->value) < abs(target - val)) val = root->value;
    if(root->valule < target) val = closest(root->right, target, val);
    else if(root->valule > target) val = closest(root->left, target, val);
    return val;
}