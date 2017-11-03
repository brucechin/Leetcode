/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

/*

level用来记录当前层数，result如果size等于level就在result里新建一个空的vector

*/

class Solution {
public:
    vector<vector<int>> result;
    void helper(TreeNode* root,int level){
        if(root != NULL){
            if(level == result.size()){
                result.push_back(vector<int>());
            }
            result[level].push_back(root->val);
            helper(root->left,level+1);
            helper(root->right,level+1);
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        helper(root,level);
        return result;
    }
};
