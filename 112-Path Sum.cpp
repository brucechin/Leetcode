/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

/*

recursion没啥难度

*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->val == sum && !root->left && !root->right) return true;
        bool left = hasPathSum(root->left,sum - root->val);
        bool right = hasPathSum(root->right,sum- root->val);
        return left || right;
    }
};
